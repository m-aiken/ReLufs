#include "CustomLookAndFeel.h"
#include "Theme.h"

/*---------------------------------------------------------------------------
**
*/
CustomLookAndFeel::CustomLookAndFeel()
{
}

/*---------------------------------------------------------------------------
**
*/
void
CustomLookAndFeel::drawRotarySlider(juce::Graphics& g,
                                    int             x,
                                    int             y,
                                    int             width,
                                    int             height,
                                    float           slider_pos_proportional,
                                    float           rotary_start_angle,
                                    float           rotary_end_angle,
                                    juce::Slider&   slider)
{
    juce::ignoreUnused(slider);

    juce::Rectangle< float > bounds(x, y, width, height);
    float                    radius         = juce::jmin(width, height) * 0.5f;
    float                    path_thickness = 4.f;
    float                    arc_radius     = radius - (path_thickness * 0.5f);

    // Fill.
    g.setColour(Theme::getColour(slider.isEnabled() ? Theme::ROTARY_FILL : Theme::DISABLED_WIDGET));

    juce::Path fill_path;

    fill_path.addCentredArc(bounds.getCentreX(),
                            bounds.getCentreY(),
                            arc_radius,
                            arc_radius,
                            0.f,
                            rotary_start_angle,
                            rotary_end_angle,
                            true);

    g.strokePath(fill_path, juce::PathStrokeType(path_thickness));

    // Arc.
    g.setColour(Theme::getColour(slider.isEnabled() ? Theme::ROTARY_ARC : Theme::DISABLED_WIDGET));

    juce::Path arc_path;

    arc_path.addCentredArc(bounds.getCentreX(),
                           bounds.getCentreY(),
                           arc_radius,
                           arc_radius,
                           0.f,
                           rotary_start_angle,
                           slider_pos_proportional,
                           true);

    g.strokePath(arc_path, juce::PathStrokeType(path_thickness));
}

/*---------------------------------------------------------------------------
**
*/
void
CustomLookAndFeel::drawLinearSlider(juce::Graphics&           g,
                                    int                       x,
                                    int                       y,
                                    int                       width,
                                    int                       height,
                                    float                     slider_pos,
                                    float                     min_slider_pos,
                                    float                     max_slider_pos,
                                    juce::Slider::SliderStyle slider_style,
                                    juce::Slider&             slider)
{
    juce::ignoreUnused(x, y, height, min_slider_pos, max_slider_pos, slider_style, slider);

    float                    thumb_diameter = static_cast< float >(width);
    juce::Rectangle< float > thumb_bounds(0.f, slider_pos - (thumb_diameter * 0.5f), thumb_diameter, thumb_diameter);

    g.setColour(Theme::getColour(slider.isEnabled() ? Theme::BAND_VALUE : Theme::DISABLED_WIDGET));
    g.fillEllipse(thumb_bounds);
}

/*---------------------------------------------------------------------------
**
*/
void
CustomLookAndFeel::fillTextEditorBackground(juce::Graphics& g, int width, int height, juce::TextEditor& editor)
{
    g.setColour(Theme::getColour(Theme::TEXTBOX_BG));
    g.fillRoundedRectangle(editor.getLocalBounds().toFloat(), 8.f);
}

/*---------------------------------------------------------------------------
**
*/
void
CustomLookAndFeel::drawTextEditorOutline(juce::Graphics& g, int width, int height, juce::TextEditor& editor)
{
    // No outline, do nothing...
}

/*---------------------------------------------------------------------------
**
*/
void
CustomLookAndFeel::drawPopupMenuBackgroundWithOptions(juce::Graphics&                 g,
                                                      int                             width,
                                                      int                             height,
                                                      const juce::PopupMenu::Options& options)
{
    g.fillAll(Theme::getColour(Theme::MAIN_BG));
}

/*---------------------------------------------------------------------------
**
*/
void
CustomLookAndFeel::drawPopupMenuItemWithOptions(juce::Graphics&                 g,
                                                const juce::Rectangle< int >&   area,
                                                bool                            is_highlighted,
                                                const juce::PopupMenu::Item&    item,
                                                const juce::PopupMenu::Options& options)
{
    g.fillAll(Theme::getColour(is_highlighted ? Theme::MENU_ITEM_BG_FOCUS : Theme::MENU_ITEM_BG));

    g.setFont(Theme::getFont());
    g.setColour(Theme::getColour(Theme::TEXT));
    g.drawFittedText(item.text, area, juce::Justification::centred, 1);
}

/*---------------------------------------------------------------------------
**
*/
int
CustomLookAndFeel::getPopupMenuBorderSize()
{
    return 0;
}

/*---------------------------------------------------------------------------
** End of File
*/
