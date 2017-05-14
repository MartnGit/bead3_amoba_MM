#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "graphics.hpp"
#include "tabla.hpp"

using namespace genv;


class JatekMester
{
    int XX, YY;
    event ev;
    Tabla tabla;


public:
    JatekMester(int XX_, int YY_);
    void EventCycle();
};

#endif
