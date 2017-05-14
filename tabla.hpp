#ifndef TABLA_HPP_INCLUDED
#define TABLA_HPP_INCLUDED

#include "widget.hpp"


class Tabla : public Widget
{
    int colWidth, lineHeight;
    int clickPosX, clickPosY;
    int CalcDrawPosX(int IndexX);
    int CalcDrawPosY(int IndexY);
public:
    Tabla(int posX_, int posY_, int width_, int height_);
    virtual void Draw();
    virtual void Handle(genv::event ev);

    int CalcIndexX();
    int CalcIndexY();

    void DrawMark(int IndexX, int IndexY, bool isRed);
};

#endif
