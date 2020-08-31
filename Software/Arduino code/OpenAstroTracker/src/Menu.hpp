#pragma once

#include "inc/Config.hpp"
#include <WString.h>
#include <Vector.h>
#include "Mount.hpp"

/*
* This is the base class for all menu items to be displayed.
*/
class MenuItem
{
private:
    String title;

public:
    MenuItem(String title = "") : title(title) {}

    String getTitle()
    {
        return title;
    }

    virtual String getContent() 
    {
        return "";
    }
};

class SubMenu : public MenuItem
{
private:
    Vector<MenuItem> items;
public:
    SubMenu(const String title) : MenuItem(title) {}

    void addItem(MenuItem item) {
        items.push_back(item);
    }

    Vector<MenuItem> getItems() {
        return items;
    }

    String getContent() override
    {
        return "TODO";
    }
};

class Menu
{
private:
    const Mount &mount;
    Vector<MenuItem> &items;

public:
    Menu(const Mount &mount, Vector<MenuItem> &items);
    void loop();
};