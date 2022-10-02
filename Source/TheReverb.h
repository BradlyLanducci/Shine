/*
  ==============================================================================

    TheReverb.h
    Created: 1 Oct 2022 10:54:57pm
    Author:  bradl

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "DelayLine.h"

class TheReverb
{
public:
    TheReverb();
    ~TheReverb();
    
    void createDelays();

    void process(juce::AudioBuffer<float>& buffer, std::vector<float*> channels);

private:
    std::vector<DelayLine> delays;

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