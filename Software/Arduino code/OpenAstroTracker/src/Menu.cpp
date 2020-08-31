#include "Menu.hpp"
#include "Mount.hpp"

Menu::Menu(const Mount &mount, Vector<MenuItem> &items) : mount(mount), items(items) {}

void Menu::loop()
{
    switch (mount.getState())
    {
    case Mount::State::PARKED:

        break;
    case Mount::State::TRACKING:

        break;

    default:
        break;
    }
}
