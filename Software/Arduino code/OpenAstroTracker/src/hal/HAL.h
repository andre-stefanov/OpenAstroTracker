#pragma once

#define XSTR(V...) #V

// only include human interface device if one was configured
#if DISPLAY_TYPE != DISPLAY_NONE
#include "HID/HID.hpp"

#if DISPLAY_TYPE == DISPLAY_LCD1602_KEYPAD
#include "HID/LCD_1602_Keypad/LCD_1602_Keypad.hpp"
#elif DISPLAY_TYPE == DISPLAY_TFT_ILI9341
#include "HID/ILI9341/ILI9341.hpp"
#endif

#endif

namespace hal
{
#if DISPLAY_TYPE != DISPLAY_NONE
    namespace hid
    {

        static HID *create(Menu *menu)
        {
#if DISPLAY_TYPE == DISPLAY_LCD1602_KEYPAD
            return new LCD_1602_Keypad(menu);
#elif DISPLAY_TYPE == DISPLAY_TFT_ILI9341
            return new ILI9341(menu);
#endif
        }

    } // namespace hid
#endif
} // namespace hal