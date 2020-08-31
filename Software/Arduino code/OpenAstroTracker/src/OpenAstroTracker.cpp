#include <log4arduino.h>
#include <Vector.h>

#include "inc/Config.hpp"
#include "Mount.hpp"
#include "Menu.hpp"
#include "hal/HAL.h"

#include HAL_HID_PATH(hal)

Mount mount;

MenuItem submenu_storage[5];
Vector<MenuItem> menu_items(submenu_storage);

Menu menu = Menu(
    mount,
    menu_items);

DISPLAY(display, menu);

void initMenu() {
    menu_items.push_back(SubMenu("item 1"));
    menu_items.push_back(SubMenu("item 2"));
}

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    // Initialize logging
    LOG_INIT(&DEBUG_SERIAL);

    // Here it begins
    LOG("Hello universe!");
}

void loop()
{
    mount.loop();
    menu.loop();
    display.update();
}