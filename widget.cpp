#include "widget.hpp"


Widget::Widget(int posX_, int posY_) : posX(posX_), posY(posY_)
{
    colorWin.r=200; colorWin.g=200; colorWin.b=200;
    colorBgr.r=240; colorBgr.g=240; colorBgr.b=240;
    colorSelected.r=200; colorSelected.g=255; colorSelected.b=255;
}
