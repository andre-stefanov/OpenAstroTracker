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
    friend class SubMenu;
};

/*
* A sub menu is just a container for multiple menu items which can be grouped together logically.
*/
class SubMenu : public MenuItem
{
private:
    LinkedList<MenuItem *> items;

public:
    SubMenu(String title) : MenuItem(title) {}
    MenuItemType getType() const;

    int size();
    MenuItem *get(int index);
    bool add(MenuItem *item);
};

template <class T>
class ValueMenuItem : public MenuItem
{
private:
    const void (*onSet)(T);
protected:
    ValueMenuItem(String title, const void (*onSet)(T)) : MenuItem(title), onSet(onSet) {}
};

class IntegerMenu : public ValueMenuItem<int>
{
public:
    IntegerMenu(String title, const void (*onSet)(int)) : ValueMenuItem(title, onSet) {}
    MenuItemType getType() const;
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