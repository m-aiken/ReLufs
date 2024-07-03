#pragma once

#include <JuceHeader.h>

//#define TEST_FFT_ACCURACY 1

namespace Global
{

static const float MAX_DB  = 12.f;
static const float NEG_INF = -48.f;

static const float MAX_DB_BOOST = 12.f;
static const float MAX_DB_CUT   = -12.f;

static const float MIN_HZ = 20.f;
static const float MAX_HZ = 20000.f;

static bool SHOW_DEBUG_BOUNDS = false;

enum PATH_DISPLAY_MODE {
    PATH_STROKE,
    PATH_FILL,
};

static const uint8 ANALYSER_PADDING          = 32;
static const float ANALYSER_MARKER_FONT_SIZE = 12.f;

namespace Channels
{

    static const uint8 NUM_INPUTS  = 4;
    static const uint8 NUM_OUTPUTS = 2;

    enum CHANNEL_ID {
        PRIMARY_LEFT,
        PRIMARY_RIGHT,
        SIDECHAIN_LEFT,
        SIDECHAIN_RIGHT,
    };

    static const std::map< CHANNEL_ID, juce::String > CHANNEL_NAME_MAP = {
        { PRIMARY_LEFT, "Primary Input Left" },
        { PRIMARY_RIGHT, "Primary Input Right" },
        { SIDECHAIN_LEFT, "Sidechain Input Left" },
        { SIDECHAIN_RIGHT, "Sidechain Input Right" },
    };

    static const juce::String getName(CHANNEL_ID channel_id)
    {
        return CHANNEL_NAME_MAP.at(channel_id);
    }

}  // namespace Channels

namespace Meters
{

    enum METER_TYPE {
        PEAK_METER,
        RMS_METER,
        LUFS_METER,
    };

}  // namespace Meters

namespace FFT
{

    static const uint8 NUM_BUFFERS = 6;

    enum BUFFER_ID {
        PRIMARY_LEFT_PRE_EQ,
        PRIMARY_RIGHT_PRE_EQ,
        PRIMARY_LEFT_POST_EQ,
        PRIMARY_RIGHT_POST_EQ,
        SIDECHAIN_LEFT,
        SIDECHAIN_RIGHT,
    };

}  // namespace FFT

}  // namespace Global

namespace GuiParams
{

enum PARAM_ID {
    EQ_INTENSITY,
    SHOW_FFT_PRIMARY_PRE_EQ,
    SHOW_FFT_PRIMARY_POST_EQ,
    SHOW_FFT_SIDECHAIN,
    FFT_ACCURACY_TEST_TONE_HZ,
    FFT_ACCURACY_TEST_TONE_DB,
};

static const std::map< PARAM_ID, juce::String > PARAM_NAME_MAP = {
    { EQ_INTENSITY, "EQ_INTENSITY" },
    { SHOW_FFT_PRIMARY_PRE_EQ, "SHOW_FFT_PRIMARY_PRE_EQ" },
    { SHOW_FFT_PRIMARY_POST_EQ, "SHOW_FFT_PRIMARY_POST_EQ" },
    { SHOW_FFT_SIDECHAIN, "SHOW_FFT_SIDECHAIN" },
    { FFT_ACCURACY_TEST_TONE_HZ, "FFT_ACCURACY_TEST_TONE_HZ" },
    { FFT_ACCURACY_TEST_TONE_DB, "FFT_ACCURACY_TEST_TONE_DB" },
};

static const juce::String
getName(PARAM_ID param_id)
{
    return PARAM_NAME_MAP.at(param_id);
}

}  // namespace GuiParams