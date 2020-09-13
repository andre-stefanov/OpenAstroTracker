#include "../../../inc/Config.hpp"

#if DISPLAY_TYPE == DISPLAY_TFT_ILI9341

#include "ILI9341.hpp"

ILI9341::ILI9341(Menu *menu) : HID(menu) {}

void ILI9341::loop() const {

}

#endif