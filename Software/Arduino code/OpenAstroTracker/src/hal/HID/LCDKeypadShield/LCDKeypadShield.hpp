#pragma once

#include "../HID.hpp"
#include "LiquidCrystal.h"

class LCDKeypadShield : public HID
{
private:
    LiquidCrystal lcd;
public:
    LCDKeypadShield(Menu &menu);

    void update() override;
};