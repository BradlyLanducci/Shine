/*
  ==============================================================================

    shineProcessor.h
    Created: 18 Sep 2022 6:18:49pm
    Author:  bradl

  ==============================================================================
*/

#pragma once
#include "DelayLine.h"
#include "JuceHeader.h"


class ShineProcessor
{
public:
    ShineProcessor();
    ~ShineProcessor();

    void process(juce::AudioBuffer<float>& buffer);

private:
    DelayLine dl_L1;
    DelayLine dl_R1;
    DelayLine dl_L2;
    DelayLine dl_R2;
    DelayLine dl_L3;
    DelayLine dl_R3;
    DelayLine dl_L4;
    DelayLine dl_R4;
    DelayLine dl_L5;
    DelayLine dl_R5;
    DelayLine dl_L6;
    DelayLine dl_R6;
    DelayLine dl_L7;
    DelayLine dl_R7;
    DelayLine dl_L8;
    DelayLine dl_R8;
    DelayLine dl_L9;
    DelayLine dl_R9;
    DelayLine dl_L10;
    DelayLine dl_R10;
    DelayLine dl_L11;
    DelayLine dl_R11;
    DelayLine dl_L12;
    DelayLine dl_R12;
};
