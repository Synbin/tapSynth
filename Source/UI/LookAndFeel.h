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

enum class KnobColour { RED, GREY, ORANGE };

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
        const int numFrames = (knob.getHeight() / knobWidth) - 1;
        const int frameId = static_cast<int>(ceil(rotation * static_cast<double>(numFrames)));
        g.drawImage(knob, x, y, knobWidth, knobHeight, 0, frameId * knobHeight, knobWidth, knobHeight);
    }

private:
    juce::Image knob;
    const int knobWidth = 64;
    const int knobHeight = 64;
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
        const int numFrames = (knob.getHeight() / knobWidth) - 1;
        const int frameId = static_cast<int>(ceil(rotation * static_cast<double>(numFrames)));
        g.drawImage(knob, x, y, knobWidth, knobHeight, 0, frameId * knobHeight, knobWidth, knobHeight);
    }

private:
    juce::Image knob;
    const int knobWidth = 64;
    const int knobHeight = 64;
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
        const int numFrames = (knob.getHeight() / knobWidth) - 1;
        const int frameId = static_cast<int>(ceil(rotation * numFrames));
        g.drawImage(knob, x, y, knobWidth, knobHeight, 0, frameId * knobHeight, knobWidth, knobHeight);
    }

private:
    juce::Image knob;
    const int knobWidth = 64;
    const int knobHeight = 64;
};

class SliderKnob : public juce::LookAndFeel_V4
{
public:
    SliderKnob()
    {
        knob = juce::ImageCache::getFromMemory(BinaryData::sliderKnob_png, BinaryData::sliderKnob_pngSize);
    }

    // ============================================================================================
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
    {
        const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
        const int numFrames = (knob.getHeight() / sliderHeight) - 1;
        const int frameId = static_cast<int>(ceil(rotation * static_cast<double>(numFrames)));

        g.drawImage(knob, x, y, sliderWidth, sliderHeight, 0, frameId * sliderHeight, sliderWidth, sliderHeight);
    }

private:
    juce::Image knob;
    const int sliderWidth = 32;
    const int sliderHeight = 107;
};

#pragma warning ( default:4100 )
