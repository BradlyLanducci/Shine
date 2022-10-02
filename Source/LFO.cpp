/*
  ==============================================================================

    lfo.cpp
    Created: 20 Sep 2022 9:33:53pm
    Author:  bradl

  ==============================================================================
*/

#include "LFO.h"

void LFO::setSampleRate(double _samplerate)
{
    time = 0;
    sampleRate = _samplerate;
}

void LFO::setFrequency(float _frequency)
{
    frequency = _frequency;
}

double LFO::getSampleRate() const
{
    return sampleRate;
}

void LFO::setShape(int _shape)
{
    if (_shape == 0)
    {
        shape = 0;
    }
    if (_shape == 1)
    {
        shape = 1;
    }
    if (_shape == 2)
    {
        shape = 2;
    }
    if (_shape == 4)
    {
        shape = 4;
    }
}

float LFO::lfo_next_cycle()
{
    const float twoPI = 2.0f * M_PI;

    // Sine
    if (shape == 0)
    {
        const float lfo_cycle = (sin((2 * M_PI) * frequency * time + phase));
        time += (1 / sampleRate);
        return lfo_cycle;
    }

    // Downwards Saw -- Intermodulation Distortion -- high frequency modulation, creates harmonics that are out of key
    else if (shape == 1)
    {
        const float lfo_cycle = 1.0f - (time / M_PI) + 0.0f;
        time += (twoPI * (450.f + (550.f * frequency) / sampleRate));
        while (time >= twoPI)
            time -= twoPI;
        return lfo_cycle;
    }

    // Triangle
    else if (shape == 2)
    {
        const float val = -1.0f + (time / M_PI);
        const float lfo_cycle = 2.0f * (abs(val) - 0.5f) + 0.0f;
        time += (twoPI * frequency / sampleRate);
        while (time >= twoPI)
            time -= twoPI;
        return lfo_cycle;
    }

    else
    {
        return 0.0f;
    }
}

void LFO::setPhase(float _phase)
{
    phase = _phase;
}
