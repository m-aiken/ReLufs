#pragma once

#include <JuceHeader.h>

#include "IntensityLabel.h"
#include "../widgets/RotaryControl.h"

class IntensityControl : public juce::Component
{
public:
    IntensityControl(juce::AudioProcessorValueTreeState& apvts);

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    IntensityLabel widget_label_;
    IntensityLabel min_label_;
    IntensityLabel max_label_;
    RotaryControl  rotary_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IntensityControl)
};
