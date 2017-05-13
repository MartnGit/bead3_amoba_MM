#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "graphics.hpp"

using namespace genv;


class JatekMester
{
    const int XX, YY;
    event ev;


public:
    JatekMester(int XX_, int YY_);
    void EventCycle;
};

#endif
