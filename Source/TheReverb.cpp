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
    lfo_L1.setFrequency(0.1f);
    lfo_L1.setSampleRate(48000.f);
    lfo_L1.setShape(0);
    lfo_R1.setFrequency(0.1f);
    lfo_R1.setSampleRate(48000.f);
    lfo_R1.setShape(0);
}

TheReverb::~TheReverb()
{
}



void TheReverb::process(juce::AudioBuffer<float>& buffer, std::vector<float*> channels)
{
    auto dryChannelL = buffer.getWritePointer(0);
    auto dryChannelR = buffer.getWritePointer(1);

    UpdateFilters();

    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {
        float len = 20000.f;
        int i = 1;

        for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel+=2)
        {
            const float LFO_CYCLE_R = lfo_R1.lfo_next_cycle() * 0.1f + 0.f;
            const float LFO_CYCLE_L = lfo_L1.lfo_next_cycle() * 0.1f + 0.f;
            float wetSampleL = delays[stereoChannel].ReadFrac(len / ((float)i++ - 0.5f) + fabs((200.f / i) * LFO_CYCLE_L));
            float wetSampleR = delays[stereoChannel+1].ReadFrac(len / ((float)i++ - 0.5f) + fabs((200.f / i) * LFO_CYCLE_R));

            wetSampleL = filters[stereoChannel].processSample(wetSampleL);
            wetSampleR = filters[stereoChannel+1].processSample(wetSampleR);

            delays[stereoChannel].Write(0.5f * channels[stereoChannel][sample] + wetSampleR);
            delays[stereoChannel+1].Write(0.5f * wetSampleL);   

            channels[stereoChannel][sample] += wetSampleL;
            channels[stereoChannel+1][sample] += wetSampleR;
        }
    }

    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {
        for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel += 2)
        {
            dryChannelL[sample] += channels[stereoChannel][sample];
            dryChannelR[sample] += channels[stereoChannel + 1][sample];
        }
        dryChannelL[sample] /= 10000.f;
        dryChannelR[sample] /= 10000.f;

        dryChannelL[sample] = allPassL1.process_so(dryChannelL[sample]);
        dryChannelR[sample] = allPassR1.process_so(dryChannelR[sample]);

        dryChannelL[sample] = allPassL2.process_so(dryChannelL[sample]);
        dryChannelR[sample] = allPassR2.process_so(dryChannelR[sample]);

        dryChannelL[sample] = allPassL3.process_so(dryChannelL[sample]);
        dryChannelR[sample] = allPassR3.process_so(dryChannelR[sample]);

        dryChannelL[sample] = peakingFilterL1.processSample(dryChannelL[sample]);
        dryChannelR[sample] = peakingFilterR1.processSample(dryChannelR[sample]);

        //dryChannelL[sample]= filter_L2.processSample(dryChannelL[sample]);
        //dryChannelR[sample]= filter_R2.processSample(dryChannelR[sample]);

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

void TheReverb::createFilters()
{
    filters.push_back(filter_L1);
    filters.push_back(filter_R1);

    filters.push_back(filter_L2);
    filters.push_back(filter_R2);

    filters.push_back(filter_L3);
    filters.push_back(filter_R3);

    filters.push_back(filter_L4);
    filters.push_back(filter_R4);

    filters.push_back(filter_L5);
    filters.push_back(filter_R5);

    filters.push_back(filter_L6);
    filters.push_back(filter_R6);

    filters.push_back(filter_L7);
    filters.push_back(filter_R7);

    filters.push_back(filter_L8);
    filters.push_back(filter_R8);

    filters.push_back(filter_L9);
    filters.push_back(filter_R9);

    filters.push_back(filter_L10);
    filters.push_back(filter_R10);

    filters.push_back(filter_L11);
    filters.push_back(filter_R11);

    filters.push_back(filter_L12);
    filters.push_back(filter_R12);

    for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel++)
    {
        filters[stereoChannel].setSampleRate(48000.f);
    }

    allPassL1.setSampleRate(48000.f);
    allPassR1.setSampleRate(48000.f);
    allPassL2.setSampleRate(48000.f);
    allPassR2.setSampleRate(48000.f);
    allPassL3.setSampleRate(48000.f);
    allPassR3.setSampleRate(48000.f);
    peakingFilterL1.setSampleRate(48000.f);
    peakingFilterR1.setSampleRate(48000.f);
}

void TheReverb::UpdateFilters()
{
    allPassL1.setAPCoefficients(0.1f, 0.1f);
    allPassR1.setAPCoefficients(0.1f, 0.1f);

    allPassL2.setAPCoefficients(0.1f, 0.1f);
    allPassR2.setAPCoefficients(0.1f, 0.1f);

    allPassL3.setAPCoefficients(0.1f, 0.1f);
    allPassR3.setAPCoefficients(0.1f, 0.1f);

    peakingFilterR1.setPeakingCoefficients(250.f, 1.414f, -7.5f);
    peakingFilterL1.setPeakingCoefficients(250.f, 1.414f, -7.5f);

    for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel += 2)
    {
        filters[stereoChannel].setLPCoefficients(3000.f, 0.5f);
        filters[stereoChannel+1].setLPCoefficients(3000.f, 0.5f);
    }
}