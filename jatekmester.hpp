#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "graphics.hpp"
#include "tabla.hpp"


class JatekMester
{
    int XX, YY;
    genv::event ev;
    Tabla tabla;


public:
    JatekMester(int XX_, int YY_);
    void EventCycle();
};

#endif
