/*
  ==============================================================================

    filters.h
    Created: 30 Aug 2022 10:13:37pm
    Author:  bradl

    Implementation of RBJ Audio EQ Cookbook Equations

  ==============================================================================
*/

#pragma once

#define _USE_MATH_DEFINES

#include "math.h"

class Filters
{
public:
    Filters()
    {
    }

    ~Filters() = default;

    void setSampleRate(double _s_rate);
    void setPeakingCoefficients(float _cutoffFreq, float _qualityFactor, float _gain);
    void setLPCoefficients(float _cutoffFreq, float _qualityFactor);
    void setHPCoefficients(float _cutoffFreq, float _qualityFactor);
    float processSample(float in);
    float* getCoefficients();
    void setCoefficients(float* coefficients);

private:
    float x1 = 0.f;
    float x2 = 0.f;

    float y1 = 0.f;
    float y2 = 0.f;

    float a0 = 0.f;
    float a1 = 0.f;
    float a2 = 0.f;

    float b0 = 0.f;
    float b1 = 0.f;
    float b2 = 0.f;

    float cutoffFreq = 0.f;
    float qualityFactor = 0.f;
    float s_rate = 0.f;
    float gain = 0.f;

    float w0 = 0.f;
    float sn = 0.f;
    float cs = 0.f;

    float alphaQ = 0.f;
    float alphaBW = 0.f;
    float alphaS = 0.f;

    float A = 0.f;
};