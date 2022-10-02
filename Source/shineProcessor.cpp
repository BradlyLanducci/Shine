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

    DBG(channels.size());

    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {
        float wetSampleL = dl_L1.ReadFrac(1000.f);
        float wetSampleR = dl_R1.ReadFrac(1000.f);

        dl_L1.Write(0.5f * channels[1][sample] + wetSampleR);
        dl_R1.Write(0.5f * wetSampleL);

        channels[0][sample] = channels[0][sample] + wetSampleL;
        channels[1][sample] = channels[1][sample] + wetSampleR;
    }
}
