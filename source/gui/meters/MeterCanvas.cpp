#include "GlobalConstants.h"
#include "MeterCanvas.h"
#include "Theme.h"

/*static*/ const uint8 MeterCanvas::DB_INTERVAL = 3;

/*---------------------------------------------------------------------------
**
*/
void
MeterCanvas::paint(juce::Graphics& g)
{
    g.fillAll(Theme::getColour(Theme::METER_BACKGROUND));

    auto      bounds        = getLocalBounds();
    auto      bounds_width  = bounds.getWidth();
    auto      bounds_height = bounds.getHeight();
    const int min_db        = static_cast< int >(Global::METER_NEG_INF);
    const int max_db        = static_cast< int >(Global::METER_MAX_DB);
    auto      line_colour   = Theme::getColour(Theme::ANALYSER_GRID);
    auto      alpha         = Theme::dark_mode ? 0.1f : 0.2f;

    g.setColour(line_colour.withAlpha(alpha));

    // dB markers (vertical - the meters are horizontal).
    for (int i = min_db; i <= max_db; i += DB_INTERVAL) {
        int x = juce::roundToInt(juce::jmap< float >(i, min_db, max_db, 0, bounds_width));

        g.fillRect(x, 0, 1, bounds_height);
    }
}

/*---------------------------------------------------------------------------
** End of File
*/
