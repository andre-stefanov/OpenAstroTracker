#pragma once

#include "../../../inc/Config.hpp"
#if DISPLAY_TYPE == DISPLAY_LCD1602_KEYPAD

#include "../HID.hpp"
#include "LiquidCrystal.h"

class LCD_1602_Keypad : public HID
{
private:
    LiquidCrystal lcd;
    
    MenuItem *current;
    MenuItem *next;
    MenuItem *prev;
public:
    LCD_1602_Keypad(Menu *menu);
    void loop();
};

#endif