#pragma once

#include "stdint.h"
#include "vector"

#define BUF_SIZE 480000

class DelayLine
{
public:
	DelayLine();
	~DelayLine();

	// Set buffer memory
	void setMemory();

	// Clear Buffer
	void clear();

	// Write sample and shift all samples
	void write(float sample);

	float linint(const float fr, const float x0, const float x1) const;

	// Read item at offset location
	float read(int offset);
	float readfrac(float offset);
private:
	int writeidx;
	std::vector<float>* delayBuffer;
};

