#include "DelayLine.h"

DelayLine::DelayLine()
{
	SetMemory();
	Clear();
}

DelayLine::~DelayLine()
{
}

void DelayLine::SetMemory()
{
	delayBuffer.resize(BUF_SIZE);
	writeidx = 5;
}

void DelayLine::Clear()
{
	std::fill(delayBuffer.begin(), delayBuffer.end(), 0);
}

void DelayLine::Write(float sample)
{
	delayBuffer[writeidx++] =  sample;
	writeidx %= BUF_SIZE;
}

float DelayLine::Read(int offset)
{
	if (offset < 0) offset = 0;
	return delayBuffer[(BUF_SIZE + (writeidx - offset)) % BUF_SIZE];
}

float DelayLine::ReadFrac(float offset)
{
	float base = (int)offset;
	float frac = offset - base;
	float s0 = Read(base);
	float s1 = Read(base + 1);
	return LinInt(frac, s0, s1);
}

float DelayLine::LinInt(const float fr, const float x0, const float x1) const 
{ 
	return x0 + fr * (x1 - x0); 
}
