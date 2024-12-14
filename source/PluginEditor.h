#pragma once

#include "CustomLookAndFeel.h"
#include "EqIntensity.h"
#include "FilterResponseGraph.h"
#include "LufsMetersWidget.h"
#include "MasterGain.h"
#include "MenuButton.h"
#include "MonoWaveform.h"
#include "PluginProcessor.h"
#include "PowerButton.h"
#include "ProfileButtonGroup.h"
#include "RecordButton.h"
#include "ThemeButton.h"

class PluginEditor final
    : public juce::AudioProcessorEditor
    , public juce::Button::Listener
{
public:
    explicit PluginEditor(PluginProcessor& p);
    ~PluginEditor() override;

    void paint(juce::Graphics& g) override;
    void resized() override;

    void buttonClicked(juce::Button* button) override;

private:
    static const uint16 MAIN_WINDOW_MIN_WIDTH;
    static const uint16 MAIN_WINDOW_MIN_HEIGHT;
    static const uint16 MAIN_WINDOW_MAX_WIDTH;
    static const uint16 MAIN_WINDOW_MAX_HEIGHT;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginProcessor& processor_ref_;

    PowerButton         power_button_;
    RecordButton        analyse_input_button_;
    MenuButton          show_fft_button_;
    ProfileButtonGroup  profile_buttons_;
    ThemeButton         theme_button_;
    FilterResponseGraph filter_res_graph_;
    EqIntensity         eq_intensity_;
    MasterGain          master_gain_;
    LufsMeterWidget     lufs_meters_;

    MonoWaveform& mono_waveform_ref_;

    CustomLookAndFeel lnf_;

    bool cached_fft_draw_status_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
