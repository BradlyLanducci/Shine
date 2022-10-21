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
#include <stdlib.h>
#include <time.h> 

class TheReverb
{
public:
    TheReverb();
    ~TheReverb();

    void UpdateFilters();
    void createDelays();
    void createFilters();
    void createADSR();

    void process(juce::AudioBuffer<float>& buffer, std::vector<float*> channels);


private:
    std::vector<DelayLine> delays;
    std::vector<Filters> filters;
    std::vector<juce::ADSR> verbAttacks;

    juce::ADSR verbAttacksL1;
    juce::ADSR verbAttacksR1;
    juce::ADSR verbAttacksL2;
    juce::ADSR verbAttacksR2;
    juce::ADSR verbAttacksL3;
    juce::ADSR verbAttacksR3;
    juce::ADSR verbAttacksL4;
    juce::ADSR verbAttacksR4;
    juce::ADSR verbAttacksL5;
    juce::ADSR verbAttacksR5;
    juce::ADSR verbAttacksL6;
    juce::ADSR verbAttacksR6;
    juce::ADSR verbAttacksL7;
    juce::ADSR verbAttacksR7;
    juce::ADSR verbAttacksL8;
    juce::ADSR verbAttacksR8;
    juce::ADSR verbAttacksL9;
    juce::ADSR verbAttacksR9;
    juce::ADSR verbAttacksL10;
    juce::ADSR verbAttacksR10;
    juce::ADSR verbAttacksL11;
    juce::ADSR verbAttacksR11;
    juce::ADSR verbAttacksL12;
    juce::ADSR verbAttacksR12;


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

    DelayLine dl_L13;
    DelayLine dl_R13;
    DelayLine dl_L14;
    DelayLine dl_R14;
    DelayLine dl_L15;
    DelayLine dl_R15;
    DelayLine dl_L16;
    DelayLine dl_R16;
    DelayLine dl_L17;
    DelayLine dl_R17;
    DelayLine dl_L18;
    DelayLine dl_R18;
    DelayLine dl_L19;
    DelayLine dl_R19;
    DelayLine dl_L20;
    DelayLine dl_R20;
    DelayLine dl_L21;
    DelayLine dl_R21;
    DelayLine dl_L22;
    DelayLine dl_R22;
    DelayLine dl_L23;
    DelayLine dl_R23;
    DelayLine dl_L24;
    DelayLine dl_R24;


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

    Filters filter_L13;
    Filters filter_R13;
    Filters filter_L14;
    Filters filter_R14;
    Filters filter_L15;
    Filters filter_R15;
    Filters filter_L16;
    Filters filter_R16;
    Filters filter_L17;
    Filters filter_R17;
    Filters filter_L18;
    Filters filter_R18;
    Filters filter_L19;
    Filters filter_R19;
    Filters filter_L20;
    Filters filter_R20;
    Filters filter_L21;
    Filters filter_R21;
    Filters filter_L22;
    Filters filter_R22;
    Filters filter_L23;
    Filters filter_R23;
    Filters filter_L24;
    Filters filter_R24;

    Filters allPassL1;
    Filters allPassR1;
    Filters allPassL2;
    Filters allPassR2;
    Filters allPassL3;
    Filters allPassR3;

    Filters peakingFilterL1;
    Filters peakingFilterR1;
};
