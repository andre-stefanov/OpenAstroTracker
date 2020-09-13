#include "../../../inc/Config.hpp"

#if DISPLAY_TYPE == DISPLAY_TFT_ILI9341

#include "../HID.hpp"

class ILI9341 : public HID
{
private:

public:
    ILI9341(Menu *menu);

    void loop() const;
};

#endif