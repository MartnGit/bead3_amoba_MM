#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "graphics.hpp"
#include "tabla.hpp"
#include "numbox.hpp"
#include <vector>

class JatekMester
{
    int XX, YY;
    genv::event ev;
    Tabla tabla;
    NumBox numBox;

    std::vector<std::vector<int>> tablaMatrix;
    //int matrixMeret;
    int indexX, indexY;
    bool isRed;




public:
    JatekMester(int XX_, int YY_);
    void EventCycle();
    bool FiveInARow();
};

#endif
