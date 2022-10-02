#pragma once

#include "stdint.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define BUF_SIZE 100000

class DelayLine
{
public:
	DelayLine();
	~DelayLine();

	// Set buffer memory
	void SetBufSize(const int bufSize);
	void SetMemory();

	// Clear Buffer
	void Clear();

	// Write sample and shift all samples
	void Write(float sample);

	// Read item at offset location
	float Read(int offset);
	float ReadFrac(float offset);

	float LinInt(const float fr, const float x0, const float x1) const;
private:
	int writeidx;
	std::vector<float> delayBuffer;
};

