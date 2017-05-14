#include "jatekmester.hpp"
#include <iostream>

using namespace genv;

JatekMester::JatekMester(int XX_, int YY_) : XX(XX_), YY(YY_), tabla(0,0, XX_, YY_), numBox(XX_/2, YY_/2, 20, 40), tablaMatrix(20, std::vector<int>(20,0))
{
    //matrixMeret=20;
    isRed=true;
}

void JatekMester::EventCycle()
{
    gout.open(XX,YY);
    tabla.Draw();
    while(gin>>ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            tabla.Handle(ev);

            indexX=tabla.CalcIndexX();
            indexY=tabla.CalcIndexY();

            if(indexX>-1 && indexY>-1 && indexX<tablaMatrix.size() && indexY<tablaMatrix.size())
            {
                if(tablaMatrix[indexX][indexY]==0)
                {
                    if(isRed) tablaMatrix[indexX][indexY]=-1;
                    else tablaMatrix[indexX][indexY]=1;
                    tabla.DrawMark(indexX,indexY,isRed);
                    isRed=!isRed;
                }
            }
        }
        gout<<refresh;
    }
}

bool JatekMester::FiveInARow()
{



}

