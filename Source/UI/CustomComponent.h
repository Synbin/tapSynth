/*
  ==============================================================================

    CustomComponent.h
    Created: 20 Feb 2021 9:51:27am
    Author:  Joshua Hodge

    22-Feb-21: Added custom coloured knobs (JS)

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "LookAndFeel.h"

//==============================================================================
/*
*/

static constexpr float fontHeight { 15.0f };

class SliderWithLabel : public juce::Component
{
public:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using SliderStyle = juce::Slider::SliderStyle;
    
    // Constructor for coloured rotary knob
    SliderWithLabel(juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts,
        const int width, const int height, KnobColour knobColour, SliderStyle style = SliderStyle::RotaryHorizontalVerticalDrag);

    // Constructor for linear slider (ADSR)
    SliderWithLabel(juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts,
        const int width, const int height, SliderStyle style = SliderStyle::RotaryVerticalDrag);

    void resized() override;
    
private:
    static constexpr int textBoxWidth { 60 };
    static constexpr int textBoxHeight { 18 };
    int sliderWidth { 0 };
    int sliderHeight { 0 };
    juce::Slider slider;
    juce::Label label;
    std::unique_ptr<SliderAttachment> attachment;

    // Coloured knobs and slider
    RedKnob redKnob;
    GreyKnob greyKnob;
    OrangeKnob orangeKnob;
    SliderKnob sliderKnob;
};

class CustomComponent  : public juce::Component
{
public:
    CustomComponent();
    ~CustomComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void setName (juce::String n) { name = n; }
    void setBoundsColour (juce::Colour c) { boundsColour = c; }

private:
    juce::String name { "" };
    juce::Colour boundsColour { juce::Colours::white };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomComponent)
};
