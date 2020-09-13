#include <log4arduino.h>

#include "inc/Config.hpp"
#include "Mount.hpp"
#include "Menu.hpp"
#include "hal/HAL.h"

Mount *mount = new Mount();

#if DISPLAY_TYPE != DISPLAY_NONE

SubMenu *menu_root = new SubMenu("Test");

Menu *menu = new Menu(
    mount,
    menu_root);

HID *hid = hal::hid::create(menu);

#endif

void setup()
{
    // Initialize logging
    DEBUG_SERIAL.begin(SERIAL_BAUD_RATE);
    LOG_INIT(&DEBUG_SERIAL);

    // Here it begins
    LOG("Hello universe!");
}

void loop()
{
    mount->loop();

#if DISPLAY_TYPE != DISPLAY_NONE
    menu->loop();
    hid->loop();
#endif
}