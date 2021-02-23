/*
  ==============================================================================

    LfoComponent.cpp
    Created: 19 Feb 2021 8:12:35pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LfoComponent.h"

//==============================================================================
LfoComponent::LfoComponent (juce::AudioProcessorValueTreeState& apvts, juce::String lfoFreqId, juce::String lfoDepthId)
: lfoFreq ("LFO Freq", lfoFreqId, apvts, dialWidth, dialHeight, KnobColour::RED)
, lfoDepth ("LFO Depth", lfoDepthId, apvts, dialWidth, dialHeight, KnobColour::RED)
{
    addAndMakeVisible (lfoFreq);
    addAndMakeVisible (lfoDepth);
}

LfoComponent::~LfoComponent()
{
}

void LfoComponent::resized()
{
    const auto yStart = 40;
    const auto width = 90;
    const auto height = 120;
        
    lfoFreq.setBounds (20, yStart, width, height);
    lfoDepth.setBounds (110, yStart, width, height);
}

