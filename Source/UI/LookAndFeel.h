/*
  ==============================================================================

    LookAndFeel.h
    Created: 22 Feb 2021 8:00:53am
    Author:  John Spink (Synbin)

  ==============================================================================
*/

#pragma once
#pragma warning( disable:4100 )

#include <JuceHeader.h>

#define KNOB_WIDTH 64
#define KNOB_HEIGHT 64

class GreyKnob : public juce::LookAndFeel_V4
{
public:
    GreyKnob()
    {
        knob = juce::ImageCache::getFromMemory(BinaryData::greyKnob_png, BinaryData::greyKnob_pngSize);
    }

    // ============================================================================================
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
    {
        const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
        const int numFrames = (knob.getHeight() / KNOB_WIDTH) - 1;
        const int frameId = (int)ceil(rotation * (double)numFrames);

        g.drawImage(knob, x, y, KNOB_WIDTH, KNOB_HEIGHT, 0, frameId * KNOB_HEIGHT, KNOB_WIDTH, KNOB_HEIGHT);
    }

private:
    juce::Image knob;
};

class RedKnob : public juce::LookAndFeel_V4
{
public:
    RedKnob()
    {
        knob = juce::ImageCache::getFromMemory(BinaryData::redKnob_png, BinaryData::redKnob_pngSize);
    }

    // ============================================================================================
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
    {
        const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
        const int numFrames = (knob.getHeight() / KNOB_WIDTH) - 1;
        const int frameId = (int)ceil(rotation * (double)numFrames);

        g.drawImage(knob, x, y, KNOB_WIDTH, KNOB_HEIGHT, 0, frameId * KNOB_HEIGHT, KNOB_WIDTH, KNOB_HEIGHT);
    }

private:
    juce::Image knob;
};

class OrangeKnob : public juce::LookAndFeel_V4
{
public:
    OrangeKnob()
    {
        knob = juce::ImageCache::getFromMemory(BinaryData::orangeKnob_png, BinaryData::orangeKnob_pngSize);
    }

    // ============================================================================================
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
    {
        const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
        const int numFrames = (knob.getHeight() / KNOB_WIDTH) - 1;
        const int frameId = (int)ceil(rotation * (double)numFrames);

        g.drawImage(knob, x, y, KNOB_WIDTH, KNOB_HEIGHT, 0, frameId * KNOB_HEIGHT, KNOB_WIDTH, KNOB_HEIGHT);
    }

private:
    juce::Image knob;
};

#pragma warning ( default:4100 )
