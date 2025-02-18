#pragma once

#include <JuceHeader.h>

class EqBandSlider
    : public juce::Slider
    , public juce::AudioProcessorParameter::Listener
{
public:
    EqBandSlider(juce::AudioProcessorValueTreeState& apvts, const juce::String& parameter_id);
    ~EqBandSlider() override;

    // Slider virtual functions.
    void paint(juce::Graphics& g) override;
    void mouseEnter(const juce::MouseEvent& e) override;

    // Listener pure virtual functions.
    void parameterValueChanged(int parameter_index, float new_value) override;
    void parameterGestureChanged(int parameter_index, bool gesture_is_starting) override;

private:
    float                    getScaledValue(const float raw_value) const;
    juce::Rectangle< float > getGhostNode(const float band_value) const;

    std::unique_ptr< juce::AudioProcessorValueTreeState::SliderAttachment > slider_attachment_;
    juce::RangedAudioParameter*                                             band_param_;

    juce::RangedAudioParameter* intensity_param_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EqBandSlider)
};
