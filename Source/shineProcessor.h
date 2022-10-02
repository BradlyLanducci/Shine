/*
  ==============================================================================

    shineProcessor.h
    Created: 18 Sep 2022 6:18:49pm
    Author:  bradl

  ==============================================================================
*/

#pragma once
#include "TheReverb.h"


class ShineProcessor
{
public:
    ShineProcessor();
    ~ShineProcessor();

    void process(juce::AudioBuffer<float>& buffer);

private:
    TheReverb theReverb;
};
