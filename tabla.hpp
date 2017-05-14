#ifndef TABLA_HPP_INCLUDED
#define TABLA_HPP_INCLUDED

#include "widget.hpp"


class Tabla : public Widget
{
    Color colorX, colorO;
    int colWidth, lineHeight;
    int clickPosX, clickPosY;
public:
    Tabla(int posX_, int posY_, int width_, int height_);
    virtual void Draw();
    virtual void Handle(genv::event ev);

    int CalcIndexX();
    int CalcIndexY();
    int CalcDrawPosX(int IndexX);
    int CalcDrawPosY(int IndexY);

    void DrawX(int IndexX, int IndexY);
    void DrawO(int IndexX, int IndexY);
};

#endif
