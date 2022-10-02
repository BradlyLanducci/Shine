/*
  ==============================================================================

    shineProcessor.cpp
    Created: 18 Sep 2022 6:18:49pm
    Author:  bradl

  ==============================================================================
*/

#include "shineProcessor.h"

ShineProcessor::ShineProcessor()
{
    theReverb.createDelays();
}

ShineProcessor::~ShineProcessor()
{
}

void ShineProcessor::process(juce::AudioBuffer<float>& buffer)
{
    std::vector<float*> channels;

    for (auto amountOfDelays = 0; amountOfDelays < 12; amountOfDelays++)
    {
        for (auto stereoChannel = 0; stereoChannel < 2; stereoChannel++)
            channels.push_back(buffer.getWritePointer(stereoChannel));
    }

    theReverb.process(buffer, channels);
}
