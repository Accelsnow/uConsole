#ifndef STATE_H
#define STATE_H

#include <bitset>
#include <array>
#include <USBComposite.h>

#include "debouncer.h"

enum class TrackballMode : uint8_t {
  Wheel,
  Mouse,
};

// corresponding arrow key is considered the "bottom"
enum class TrackballOrientation : uint8_t {
  TRACKBALL_DOWN = 0,
  TRACKBALL_UP = 1,
  TRACKBALL_LEFT = 2,
  TRACKBALL_RIGHT = 3
};

class State
{
  public:
    static const uint16_t MIDDLE_CLICK_TIMEOUT_MS = 0;

    State();

    void tick(uint8_t delta);

    bool fn;

    void pressMiddleClick();
    bool releaseMiddleClick();
    bool getScrolled();
    void setScrolled();
    TrackballMode moveTrackball();
  private:
    bool middleClick;
    bool scrolled;
    Timeout<uint16_t, MIDDLE_CLICK_TIMEOUT_MS> middleClickTimeout;
};

#endif
