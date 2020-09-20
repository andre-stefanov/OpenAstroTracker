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

int SubMenu::size()
{
    return items.size();
}

MenuItem *SubMenu::get(int index)
{
    return items.get(index);
}

bool SubMenu::add(MenuItem *item)
{
    bool result = items.add(item);
    if (result)
    {
        item->parent = this;
    }
    return result;
}

MenuItemType IntegerMenu::getType() const
{
    return MenuItemType::INTEGER;
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