/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 7 Feb 2021 2:28:49pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent (juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId)
: attack ("A", attackId, apvts, sliderWidth, sliderHeight)
, decay  ("D", decayId, apvts, sliderWidth, sliderHeight)
, sustain ("S", sustainId, apvts, sliderWidth, sliderHeight)
, release ("R", releaseId, apvts, sliderWidth, sliderHeight)
{
    addAndMakeVisible (attack);
    addAndMakeVisible (decay);
    addAndMakeVisible (sustain);
    addAndMakeVisible (release);
}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::resized()
{
    const auto startX = 25;
    const auto startY = 45;
    const auto width = 40;
    const auto height = 160;
    
    attack.setBounds (startX, startY, width, height);
    decay.setBounds (attack.getRight() + sliderPadding, startY, width, height);
    sustain.setBounds (decay.getRight() + sliderPadding, startY, width, height);
    release.setBounds (sustain.getRight() + sliderPadding, startY, width, height);
}

