#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

#include "dsp/BandUpdater.h"
#include "dsp/Equalizer.h"
#include "dsp/InputAnalysisFilter.h"
#include "dsp/MonoFftBuffer.h"
#include "utility/GlobalConstants.h"

class PluginProcessor final : public juce::AudioProcessor
{
public:
    PluginProcessor();
    ~PluginProcessor() override;

    void prepareToPlay(double sample_rate, int samples_per_block) override;
    void releaseResources() override;

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

    void processBlock(juce::AudioBuffer< float >& buffer, juce::MidiBuffer& midi_messages) override;
    using AudioProcessor::processBlock;

    juce::AudioProcessorEditor* createEditor() override;
    bool                        hasEditor() const override;

    const juce::String getName() const override;

    bool   acceptsMidi() const override;
    bool   producesMidi() const override;
    bool   isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int                getNumPrograms() override;
    int                getCurrentProgram() override;
    void               setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void               changeProgramName(int index, const juce::String& new_name) override;

    void getStateInformation(juce::MemoryBlock& dest_data) override;
    void setStateInformation(const void* data, int size_in_bytes) override;

    juce::AudioProcessorValueTreeState& getApvts();

    typedef juce::SmoothedValue< float, juce::ValueSmoothingTypes::Linear > SmoothedFloat;
    typedef std::array< SmoothedFloat, Equalizer::NUM_BANDS >               BandDbValueArray;
    typedef std::array< MonoFftBuffer, Global::FFT::NUM_BUFFERS >           FftBuffers;

    BandDbValueArray&     getBandDbValues();
    FftBuffers&           getFftBuffers();
    Equalizer::MonoChain& getFilterChain();

    float getMeterValue(Global::Meters::METER_TYPE meter_type, Global::Channels::CHANNEL_ID channel_id) const;

private:
    void  updateFilterCoefficients();
    float getBandDb(Equalizer::BAND_ID band_id);

    void setPeak(SmoothedFloat& val, juce::AudioBuffer< float >& buffer, Global::Channels::CHANNEL_ID channel);
    void setRms(SmoothedFloat& val, juce::AudioBuffer< float >& buffer, Global::Channels::CHANNEL_ID channel);
    void setLufs(SmoothedFloat& val, juce::AudioBuffer< float >& buffer, Global::Channels::CHANNEL_ID channel);

    static float getNormalisedValue(float full_range_value);

    static juce::AudioProcessorValueTreeState::ParameterLayout getParameterLayout();

private:
    juce::AudioProcessorValueTreeState apvts_;

    static const double BAND_DB_RAMP_TIME_SECONDS;
    static const double METER_DB_RAMP_TIME_SECONDS;

    BandDbValueArray    band_db_values_;
    InputAnalysisFilter input_analysis_filter_;
    BandUpdater         band_updater_;
    FftBuffers          fft_buffers_;

    Equalizer::MonoChain filter_chain_left_;
    Equalizer::MonoChain filter_chain_right_;

    SmoothedFloat peak_l_;
    SmoothedFloat peak_r_;
    SmoothedFloat rms_l_;
    SmoothedFloat rms_r_;
    SmoothedFloat lufs_l_;
    SmoothedFloat lufs_r_;

#ifdef TEST_FFT_ACCURACY
    juce::dsp::Oscillator< float > fft_test_tone_;
    juce::dsp::Gain< float >       fft_test_tone_gain_;
#endif
    void updateFftTestTone();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
