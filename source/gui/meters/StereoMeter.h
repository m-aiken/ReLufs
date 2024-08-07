#pragma once

#include <JuceHeader.h>

#include "GlobalConstants.h"
#include "MeterDbScale.h"
#include "MonoMeter.h"
#include "PluginProcessor.h"

class StereoMeter : public juce::Component
{
public:
    StereoMeter(PluginProcessor& p, Global::Meters::METER_TYPE meter_type);

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    MeterDbScale db_scale_;
    MonoMeter    meter_l_;
    MonoMeter    meter_r_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoMeter)
};
