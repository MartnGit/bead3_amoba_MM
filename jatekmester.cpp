#include "jatekmester.hpp"

using namespace genv;

JatekMester::JatekMester(int XX_, int YY_) : XX(XX_), YY(YY_), tabla(0,0, XX_, YY_) {}

void JatekMester::EventCycle()
{
    gout.open(XX,YY);
    tabla.Draw();
    while(gin>>ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            tabla.Handle(ev);
            tabla.DrawX(tabla.CalcIndexX(),tabla.CalcIndexY());

        }



        gout<<refresh;
    }
}
