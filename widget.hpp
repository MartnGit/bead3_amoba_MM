#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "color.hpp"


class Widget
{
protected:
    int posX, posY, width, height;
    Color colorWin, colorBgr, colorSelected, colorFrm, colorFont;
    bool isFocused;
public:
    Widget(int posX_, int posY_);
    Color GetColorGout() {return colorWin;}
    virtual void Draw()=0;
    virtual void Handle(genv::event ev)=0;
    bool isActive;
};

#endif
