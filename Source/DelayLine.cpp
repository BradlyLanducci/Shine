#include "DelayLine.h"
#include <stdlib.h>
#include "JuceHeader.h"

DelayLine::DelayLine()
{
	setMemory();
	clear();
}

DelayLine::~DelayLine() = default;

void DelayLine::setMemory()
{
	delayBuffer->reserve(BUF_SIZE);
	writeidx = 100000;
}

void DelayLine::clear()
{
	std::fill(delayBuffer, delayBuffer + BUF_SIZE, 0);
}

void DelayLine::write(float sample)
{
	delayBuffer->at(writeidx++) = sample;
	writeidx %= BUF_SIZE;
}

float DelayLine::read(int offset)
{
	if (offset < 0) offset = 0;
	return delayBuffer->at((BUF_SIZE + (writeidx - offset)) % BUF_SIZE);
}

float DelayLine::readfrac(float offset)
{
	const auto base = (int)offset;
	const auto frac = offset - base;
	const auto s0 = read(base);
	const auto s1 = read(base + 1);
	return linint(frac, s0, s1);
}

float DelayLine::linint(const float fr, const float x0, const float x1) const
{
	return x0 + fr * (x1 - x0);
}