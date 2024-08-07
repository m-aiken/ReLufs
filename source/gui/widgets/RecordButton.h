#pragma once

#include <JuceHeader.h>

#include "GlobalConstants.h"

class RecordButton : public juce::ToggleButton
{
public:
    RecordButton(const juce::String& label_text, juce::AudioProcessorValueTreeState& apvts, GuiParams::PARAM_ID param_id);

    void paintButton(juce::Graphics& g, bool should_draw_button_as_highlighted, bool should_draw_button_as_down) override;
    void mouseEnter(const juce::MouseEvent& e) override;

private:
    std::unique_ptr< juce::AudioProcessorValueTreeState::ButtonAttachment > attachment_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RecordButton)
};
