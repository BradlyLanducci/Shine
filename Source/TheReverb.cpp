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
    lfo_L1.setFrequency(0.09238f);
    lfo_L1.setSampleRate(48000.f);
    lfo_L1.setShape(0);
    lfo_R1.setFrequency(0.25f);
    lfo_R1.setSampleRate(48000.f);
    lfo_R1.setPhase(90);
    lfo_R1.setShape(0);

}

TheReverb::~TheReverb()
{
}



void TheReverb::process(juce::AudioBuffer<float>& buffer, std::vector<float*> channels)
{
    auto dryChannelL = buffer.getWritePointer(0);
    auto dryChannelR = buffer.getWritePointer(1);

    int haddamard[] = { 1, 1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, 1 };

    UpdateFilters();

    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {
        float len = 50000.f;
        int i = 2;
        int j = 0;

        for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel+=2)
        {
            const float LFO_CYCLE_R = lfo_R1.lfo_next_cycle() * 1.0f + 0.f;
            const float LFO_CYCLE_L = lfo_L1.lfo_next_cycle() * 1.0f + 0.f;
           
            const float test = len / ((float)i++ - 0.5f) + fabs((200.f / i) * LFO_CYCLE_L);

            float wetSampleL = delays[stereoChannel].ReadFrac(len / ((float)i++ - 0.5f) + fabs((250.f / i) * LFO_CYCLE_L));
            float wetSampleR = delays[stereoChannel+1].ReadFrac(len / ((float)i - 0.5f) + fabs((250.f / i--) * LFO_CYCLE_R));

            if (test > 20000.f)
            {
                wetSampleL = 0.0f;
                wetSampleR = 0.0f;
            }

            //if (stereoChannel < 4)
            //{
            //    wetSampleL *= 0.1f;
            //    wetSampleR *= 0.1f;
            //}

            //if (stereoChannel < 12)
            //{
            //    wetSampleL *= 0.5f;
            //    wetSampleR *= 0.5f;
            //}

            wetSampleL = filters[stereoChannel].processSample(wetSampleL);
            wetSampleR = filters[stereoChannel+1].processSample(wetSampleR);

            //verbAttacks[j].noteOn();

            //wetSampleL *= verbAttacks[j].getNextSample();
            //wetSampleR *= verbAttacks[j].getNextSample();

            delays[stereoChannel].Write(0.5f * channels[stereoChannel][sample] + wetSampleR);
            delays[stereoChannel+1].Write(0.5f * wetSampleL);   

            channels[stereoChannel][sample] += wetSampleL;
            channels[stereoChannel+1][sample] += wetSampleR;
            
            j++;
            i++;
        }
    }

    // Shuffle

    for (int sample = 0; sample < buffer.getNumSamples(); sample++)
    {

        for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel += 2)
        {
            channels[stereoChannel][sample] = channels[stereoChannel + 6 % 3][sample];
            channels[stereoChannel+1][sample] = channels[stereoChannel + 3 % 7][sample];
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
    delays.push_back(dl_L13);
    delays.push_back(dl_R13);
    delays.push_back(dl_L14);
    delays.push_back(dl_R14);
    delays.push_back(dl_L15);
    delays.push_back(dl_R15);
    delays.push_back(dl_L16);
    delays.push_back(dl_R16);
    delays.push_back(dl_L17);
    delays.push_back(dl_R17);
    delays.push_back(dl_L18);
    delays.push_back(dl_R18);
    delays.push_back(dl_L19);
    delays.push_back(dl_R19);
    delays.push_back(dl_L20);
    delays.push_back(dl_R20);
    delays.push_back(dl_L21);
    delays.push_back(dl_R21);
    delays.push_back(dl_L22);
    delays.push_back(dl_R22);
    delays.push_back(dl_L23);
    delays.push_back(dl_R23);
    delays.push_back(dl_L24);
    delays.push_back(dl_R24);
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
    filters.push_back(filter_L13);
    filters.push_back(filter_R13);
    filters.push_back(filter_L14);
    filters.push_back(filter_R14);
    filters.push_back(filter_L15);
    filters.push_back(filter_R15);
    filters.push_back(filter_L16);
    filters.push_back(filter_R16);
    filters.push_back(filter_L17);
    filters.push_back(filter_R17);
    filters.push_back(filter_L18);
    filters.push_back(filter_R18);
    filters.push_back(filter_L19);
    filters.push_back(filter_R19);
    filters.push_back(filter_L20);
    filters.push_back(filter_R20);
    filters.push_back(filter_L21);
    filters.push_back(filter_R21);
    filters.push_back(filter_L22);
    filters.push_back(filter_R22);
    filters.push_back(filter_L23);
    filters.push_back(filter_R23);
    filters.push_back(filter_L24);
    filters.push_back(filter_R24);

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

void TheReverb::createADSR()
{
    verbAttacks.push_back(verbAttacksL1);
    verbAttacks.push_back(verbAttacksR1);
    verbAttacks.push_back(verbAttacksL2);
    verbAttacks.push_back(verbAttacksR2);
    verbAttacks.push_back(verbAttacksL3);
    verbAttacks.push_back(verbAttacksR3);
    verbAttacks.push_back(verbAttacksL4);
    verbAttacks.push_back(verbAttacksR4);
    verbAttacks.push_back(verbAttacksL5);
    verbAttacks.push_back(verbAttacksR5);
    verbAttacks.push_back(verbAttacksL5);
    verbAttacks.push_back(verbAttacksR5);
    verbAttacks.push_back(verbAttacksL6);
    verbAttacks.push_back(verbAttacksR6);
    verbAttacks.push_back(verbAttacksL7);
    verbAttacks.push_back(verbAttacksR7);
    verbAttacks.push_back(verbAttacksL8);
    verbAttacks.push_back(verbAttacksR8);
    verbAttacks.push_back(verbAttacksL9);
    verbAttacks.push_back(verbAttacksR9);
    verbAttacks.push_back(verbAttacksL10);
    verbAttacks.push_back(verbAttacksR10);
    verbAttacks.push_back(verbAttacksL11);
    verbAttacks.push_back(verbAttacksR11);
    verbAttacks.push_back(verbAttacksL12);
    verbAttacks.push_back(verbAttacksR12);

    for (auto i = 0; i < 12; i++)
    {
        verbAttacks[i].setSampleRate(48000.f);
        verbAttacks[i].setParameters(juce::ADSR::Parameters(2.0f, 0.1f, 0.1f, 0.1f));
    }
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

    for (auto stereoChannel = 0; stereoChannel < 24; stereoChannel ++)
    {
        filters[stereoChannel].setLPCoefficients(8000.f, 0.5f);
    }
}