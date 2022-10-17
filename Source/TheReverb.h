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
#include "LFO.h"
#include "filters.h"

class TheReverb
{
public:
    TheReverb();
    ~TheReverb();

    void UpdateFilters();
    void createDelays();
    void createFilters();

    void process(juce::AudioBuffer<float>& buffer, std::vector<float*> channels);

private:
    std::vector<DelayLine> delays;
    std::vector<Filters> filters;

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

    LFO lfo_L1;
    LFO lfo_R1;
    
    Filters filter_L1;
    Filters filter_R1;
    Filters filter_L2;
    Filters filter_R2;
    Filters filter_L3;
    Filters filter_R3;
    Filters filter_L4;
    Filters filter_R4;
    Filters filter_L5;
    Filters filter_R5;
    Filters filter_L6;
    Filters filter_R6;
    Filters filter_L7;
    Filters filter_R7;
    Filters filter_L8;
    Filters filter_R8;
    Filters filter_L9;
    Filters filter_R9;
    Filters filter_L10;
    Filters filter_R10;
    Filters filter_L11;
    Filters filter_R11;
    Filters filter_L12;
    Filters filter_R12;

    Filters allPassL1;
    Filters allPassR1;
    Filters allPassL2;
    Filters allPassR2;
    Filters allPassL3;
    Filters allPassR3;

    Filters peakingFilterL1;
    Filters peakingFilterR1;
};
