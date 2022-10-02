/*
  ==============================================================================

    TheReverb.cpp
    Created: 1 Oct 2022 10:54:57pm
    Author:  bradl

  ==============================================================================
*/

#include "TheReverb.h"

TheReverb::TheReverb()
{
}

TheReverb::~TheReverb()
{
}

void TheReverb::process(juce::AudioBuffer<float>& buffer, std::vector<float*> channels)
{
    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {
        float len = 20000.f;
        int i = 1;

        for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel+=2)
        {
            float wetSampleL = -1.f * delays[stereoChannel].ReadFrac(len / ((float)i++ - 0.5f));
            float wetSampleR = delays[stereoChannel+1].ReadFrac(len / ((float)i++ - 0.5f));

            delays[stereoChannel].Write(0.5f * channels[stereoChannel][sample] + wetSampleR);
            delays[stereoChannel+1].Write(0.5f * wetSampleL);   

            channels[stereoChannel][sample] += wetSampleL;
            channels[stereoChannel+1][sample] += wetSampleR;
        }
    }
}

void TheReverb::createDelays()
{
    delays.push_back(dl_L1);
    delays.push_back(dl_R1);

    delays.push_back(dl_L2);
    delays.push_back(dl_R2);

    delays.push_back(dl_L3);
    delays.push_back(dl_R3);

    delays.push_back(dl_L4);
    delays.push_back(dl_R4);

    delays.push_back(dl_L5);
    delays.push_back(dl_R5);

    delays.push_back(dl_L6);
    delays.push_back(dl_R6);

    delays.push_back(dl_L7);
    delays.push_back(dl_R7);

    delays.push_back(dl_L8);
    delays.push_back(dl_R8);

    delays.push_back(dl_L9);
    delays.push_back(dl_R9);

    delays.push_back(dl_L10);
    delays.push_back(dl_R10);

    delays.push_back(dl_L11);
    delays.push_back(dl_R11);

    delays.push_back(dl_L12);
    delays.push_back(dl_R12);
}
