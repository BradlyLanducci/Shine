/*
  ==============================================================================

    filter.cpp
    Created: 20 Sep 2022 9:33:43pm
    Author:  bradl

  ==============================================================================
*/

#include "filters.h"

void Filters::setSampleRate(double _s_rate)
{
    s_rate = (float)_s_rate;
}

// Cutoff freq is midpoint
// Quality factor (Q) is a value between 0.03f and 72.f, defining width or resonance depending on filter type
// Gain ends up being sqrt(_gain) I believe
void Filters::setPeakingCoefficients(float _cutoffFreq,
    float _qualityFactor,
    float _gain)
{
    cutoffFreq = _cutoffFreq;
    qualityFactor = _qualityFactor;
    gain = _gain;

    A = pow(10, gain / 40.f);
    w0 = (2.f * M_PI * cutoffFreq) / s_rate;
    sn = sin(w0);
    cs = cos(w0);

    alphaQ = sn / (2.0 * qualityFactor);

    a0 = 1.f + (alphaQ / (float)A);
    a1 = -2.f * cs;
    a2 = 1.f - (alphaQ / (float)A);

    b0 = 1.f + (alphaQ * A);
    b1 = -2.f * cs;
    b2 = 1.f - (alphaQ * A);
}

void Filters::setLPCoefficients(float _cutoffFreq,
    float _qualityFactor)
{
    cutoffFreq = _cutoffFreq;
    qualityFactor = _qualityFactor;

    w0 = (2.f * M_PI * cutoffFreq) / s_rate;
    sn = sin(w0);
    cs = cos(w0);

    alphaQ = sn / (2.0 * qualityFactor);

    a0 = 1.f + alphaQ;
    a1 = -2.f * cs;
    a2 = 1.f - alphaQ;

    b0 = (1.f - cs) / 2.f;
    b1 = 1.f - cs;
    b2 = (1.f - cs) / 2.f;
}

void Filters::setHPCoefficients(float _cutoffFreq,
    float _qualityFactor)
{
    cutoffFreq = _cutoffFreq;
    qualityFactor = _qualityFactor;

    w0 = (2.f * M_PI * cutoffFreq) / s_rate;
    sn = sin(w0);
    cs = cos(w0);

    alphaQ = sn / (2.0 * qualityFactor);

    a0 = 1.f + alphaQ;
    a1 = -2.f * cs;
    a2 = 1.f - alphaQ;

    b0 = (1.f + cs) / 2.f;
    b1 = -1.f * (1.f + cs);
    b2 = (1.f + cs) / 2.f;
}

void Filters::setAPCoefficients(float delta, const float radius)
{
    // Note: alternative implementation for use in phasers
    // delta = cos(2pi * wc)
    const float a1 = -2.f * radius * delta;
    const float a2 = radius * radius;
    ff0 = fb2 = a2;
    ff1 = fb1 = a1;
    ff2 = 1.f;
}

float Filters::processSample(float in)
{
    float out = 0.f;

    out = (1 / a0) * ((b0 * in) + (b1 * x1) + (b2 * x2) - (a1 * y1) - (a2 * y2));

    x2 = x1;
    x1 = in;

    y2 = y1;
    y1 = out;

    return out;
}

float Filters::process_so(const float xn) {
    float acc = ff0 * xn + mZ1;
    mZ1 = ff1 * xn + mZ2;
    mZ2 = ff2 * xn;
    mZ1 -= fb1 * acc;
    mZ2 -= fb2 * acc;
    return acc;
}

// Use to copy coefficients to another channel
float* Filters::getCoefficients()
{
    float coefficients[6] = { a0, a1, a2, b0, b1, b2 };
    return coefficients;
}

void Filters::setCoefficients(float* coefficients)
{
    a0 = coefficients[0];
    a1 = coefficients[1];
    a2 = coefficients[2];

    b0 = coefficients[3];
    b1 = coefficients[4];
    b2 = coefficients[5];
}