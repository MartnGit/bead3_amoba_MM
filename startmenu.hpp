#ifndef STARTMENU_HPP_INCLUDED
#define STARTMENU_HPP_INCLUDED

#include "widget.hpp"


class StartMenu : public Widget
{
public:
    StartMenu(int posX_, int posY_, int width_, int height_);
    virtual void Draw();
    virtual void Handle(genv::event ev){}
};

#endif
