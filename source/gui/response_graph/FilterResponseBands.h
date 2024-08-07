#pragma once

#include <JuceHeader.h>

#include "EqBandSlider.h"
#include "FilterMagnitudesCalculator.h"
#include "PluginProcessor.h"
#include "Equalizer.h"

class FilterResponseBands
    : public juce::Component
    , public juce::Timer
{
public:
    FilterResponseBands(PluginProcessor& p);
    ~FilterResponseBands() override;

    //    void paint(juce::Graphics& g) override;
    void resized() override;

    void timerCallback() override;

private:
    int  getYCoordinateFromMagnitude(double magnitude);
    void updateSliderValues();
    int  getBandBarHeight(double magnitude);
    void calculateXCoordinates();

private:
    static const uint8 BAR_WIDTH;
    static const uint8 HALF_BAR_WIDTH;

    std::array< int, Equalizer::NUM_BANDS > x_coordinates_;
    bool                                    x_coordinates_calculated_;

    std::array< std::unique_ptr< EqBandSlider >, Equalizer::NUM_BANDS > sliders_;

    FilterMagnitudesCalculator magnitudes_calculator_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FilterResponseBands)
};
