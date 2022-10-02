/*
  ==============================================================================

    LFO.h
    Created: 14 Jul 2022 10:37:23pm
    Author:  bradl

  ==============================================================================
*/
#define _USE_MATH_DEFINES

#include "JuceHeader.h"
#include <math.h>

#pragma once
class LFO
{
public:
    LFO()
    {
        shape = 0;
        phase = 0.f;
    }
    ~LFO()
    {}

    void setSampleRate(double _samplerate);

    void setFrequency(float _frequency);

    double getSampleRate() const;

    void setShape(int _shape);

    float lfo_next_cycle();

    void setPhase(float _phase);

private:
    double sampleRate;
    float frequency;
    float time;
    float phase;

    int shape;
};