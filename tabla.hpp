#ifndef TABLA_HPP_INCLUDED
#define TABLA_HPP_INCLUDED

#include "widget.hpp"


class Tabla : public Widget
{
    Color color_X, color_O;
public:
    Tabla(int, int, int width_, int height_);
    virtual void Draw();
    virtual void Handle(genv::event ev);
};

#endif
