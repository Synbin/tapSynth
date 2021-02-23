/*
  ==============================================================================

    CustomComponent.cpp
    Created: 20 Feb 2021 9:51:27am
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CustomComponent.h"

//==============================================================================

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
using SliderStyle = juce::Slider::SliderStyle;

SliderWithLabel::SliderWithLabel(juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts, const int width, const int height,
    KnobColour knobColour, SliderStyle style)
{
    sliderWidth = width;
    sliderHeight = height;

    slider.setSliderStyle(style);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    switch (knobColour) {
    case KnobColour::RED:
        slider.setLookAndFeel(&redKnob);
        break;
    case KnobColour::GREY:
        slider.setLookAndFeel(&greyKnob);
        break;
    case KnobColour::ORANGE:
        slider.setLookAndFeel(&orangeKnob);
        break;
    default:
        jassertfalse;
        break;
    }
    addAndMakeVisible(slider);

    label.setFont(fontHeight);
    label.setText(labelName, juce::dontSendNotification);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);

    attachment = std::make_unique<SliderAttachment>(apvts, paramId, slider);
}

SliderWithLabel::SliderWithLabel(juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts, const int width, const int height, SliderStyle style)
{
    sliderWidth = width;
    sliderHeight = height;

    slider.setSliderStyle(style);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    slider.setLookAndFeel(&sliderKnob);
    addAndMakeVisible(slider);

    label.setFont(fontHeight);
    label.setText(labelName, juce::dontSendNotification);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);

    attachment = std::make_unique<SliderAttachment>(apvts, paramId, slider);
}

void SliderWithLabel::resized()
{
    const auto dialToLabelRatio = 25;
    const auto labelHeight = 18;
    
    jassert (sliderWidth > 0);
    jassert (sliderHeight > 0);
    
    label.setBounds (0, 0, sliderWidth, labelHeight);
    slider.setBounds (0, dialToLabelRatio, sliderWidth, sliderHeight);
}


CustomComponent::CustomComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

CustomComponent::~CustomComponent()
{
}

void CustomComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    auto bounds = getLocalBounds();
    g.setColour (boundsColour);
    g.drawRoundedRectangle (bounds.toFloat().reduced (10.0f), 5.0f, 2.0f);
    
    g.setColour (juce::Colours::yellow);
    g.setFont (fontHeight);
    g.setFont (g.getCurrentFont().boldened());
    
    jassert (name.isNotEmpty());
    g.drawText (name, 20, 15, 100, 25, juce::Justification::left);
}

void CustomComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

