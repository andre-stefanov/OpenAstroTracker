#pragma once

#include "../../Menu.hpp"

class HID
{
private:
    Menu &menu;
public:
    HID(Menu &menu) : menu(menu) {}

    virtual void update() = 0;
};