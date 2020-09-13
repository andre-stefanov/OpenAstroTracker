#include "inc/Config.hpp"
#if DISPLAY_TYPE != DISPLAY_NONE

#include "Menu.hpp"

String MenuItem::getTitle()
{
    return this->title;
}

MenuItemType SubMenu::getType() const
{
    return MenuItemType::SUBMENU;
}

bool SubMenu::add(MenuItem* item)
{
    return LinkedList::add(item);
}

bool SubMenu::add(int index, MenuItem* item)
{
    return LinkedList::add(index, item);
}

Menu::Menu(Mount *mount, SubMenu *items) : mount(mount), items(items) {}

void Menu::loop()
{
    switch (mount->getState())
    {
    case Mount::State::PARKED:

        break;
    case Mount::State::TRACKING:

        break;

    default:
        break;
    }
}

#endif