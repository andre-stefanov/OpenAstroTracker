#pragma once

#include "inc/Config.hpp"
#if DISPLAY_TYPE != DISPLAY_NONE

#include <WString.h>
#include "Mount.hpp"
#include <LinkedList.h>

enum MenuItemType
{
    SUBMENU,
    INFO,
    BOOLEAN,
    INTEGER,
    FLOAT
};

class SubMenu;

/*
* This is the base class for all menu items to be displayed.
*/
class MenuItem
{
private:
    String title;
    SubMenu *parent;
public:
    MenuItem(String title) : title(title) {}
    virtual String getTitle();
    virtual MenuItemType getType() const = 0;
};

/*
* A sub menu is just a container for multiple menu items which can be grouped together logically.
*/
class SubMenu : public MenuItem, public LinkedList<MenuItem*>
{
private:
    SubMenu *parent;
public:
    SubMenu(String title) : MenuItem(title) {}
    MenuItemType getType() const;
    bool add(MenuItem* item);
    bool add(int index, MenuItem* item);
};

class Menu
{
private:
    Mount *mount;

public:
    SubMenu *items;

public:
    Menu(Mount *mount, SubMenu *items);
    void loop();
};

#endif