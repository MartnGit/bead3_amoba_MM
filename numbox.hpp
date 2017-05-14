#ifndef NUMBOX_HPP_INCLUDED
#define NUMBOX_HPP_INCLUDED

#include "widget.hpp"
#include <sstream>
#include <fstream>


class NumBox : public Widget
{
    Color colorBtn;
    int num; int numMax; int numMin;
    int relPosBtnUpX; int relPosBtnUpY;
    int relPosBtnDwnX; int relPosBtnDwnY;
    int relPosPlusX; int relPosPlusY;
    int relPosMinusX; int relPosMinusY;
    int relPosNumX; int relPosNumY;
public:
    NumBox(int posX_, int posY_, int numMin_, int numMax_);
    int GetNum() {return num;}
    virtual void Draw();
    virtual void Handle(genv::event ev);
    std::string StringNum(int num);
};

#endif
