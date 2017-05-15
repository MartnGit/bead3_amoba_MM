#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "graphics.hpp"
#include "startmenu.hpp"
#include "numbox.hpp"
#include "tabla.hpp"
#include <vector>

class JatekMester
{
    int XX, YY;
    genv::event ev;
    StartMenu startMenu;
    NumBox numBox;
    Tabla tabla;

    std::vector<std::vector<int>> tablaMatrix;
    int indexX, indexY;
    bool isRed;
    bool raktak;
    bool win;
    bool nemTeltBe;
    int lepesSzam;

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
