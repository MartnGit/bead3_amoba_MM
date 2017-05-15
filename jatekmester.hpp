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
    int indexX, indexY;
    bool isRed;
    bool raktak;
    bool win;
    bool nemTeltBe;

public:
    JatekMester(int XX_, int YY_);
    void EventCycle();
    void LeRak();
    void FiveInARow();
    void FiveInACol();
    void FiveInDiagonalSE();
    void FiveInDiagonalSW();
    void BeteltE();
    void StartAllapot();
};

#endif
