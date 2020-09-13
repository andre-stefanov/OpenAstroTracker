#pragma once

#include "../../Menu.hpp"

class HID
{
protected:
    Menu *menu;
public:
    HID(Menu *menu) : menu(menu) {}

    virtual void loop() = 0;
};