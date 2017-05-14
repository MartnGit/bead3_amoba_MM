#include "jatekmester.hpp"


JatekMester::JatekMester(int XX_, int YY_) : XX(XX_), YY(YY_), tabla(0,0, XX_, YY_) {}

void JatekMester::EventCycle()
{
    while(gin>>ev && ev.keycode!=key_escape)
    {
        gout.open(XX,YY);





    }
}
