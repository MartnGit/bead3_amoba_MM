#include "jatekmester.hpp"

using namespace genv;

JatekMester::JatekMester(int XX_, int YY_) : XX(XX_), YY(YY_), tabla(0,0, XX_, YY_), numBox(XX_/2, YY_/2, 10, 100), tablaMatrix(20,std::vector<int>(20,0))
{
    StartAllapot();
}

void JatekMester::EventCycle()
{
    gout.open(XX,YY);

    tabla.Draw();
    while(gin>>ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse && ev.button==btn_left && !win)
        {
            tabla.Handle(ev);
            LeRak();
            if(raktak)
            {
                FiveInARow();
                FiveInACol();
                FiveInDiagonalSE();
                FiveInDiagonalSW();
                BeteltE();
            }
        }

        if((ev.type==ev_key && ev.keycode==key_space) && (win || !nemTeltBe))
        {
            for(int i=0; i<tablaMatrix.size(); ++i){
                for(int j=0; j<tablaMatrix.size(); ++j){
                    tablaMatrix[i][j]=0;
                }
            }
            tabla.Draw();
            StartAllapot();
        }
        gout<<refresh;
    }
}

void JatekMester::LeRak()
{
    raktak=false;
    indexX=tabla.CalcIndexX();
    indexY=tabla.CalcIndexY();
    if(indexX>-1 && indexY>-1 && indexX<tablaMatrix.size() && indexY<tablaMatrix.size())
    {
        if(tablaMatrix[indexX][indexY]==0)
        {
            if(isRed) tablaMatrix[indexX][indexY]=-1;
            else tablaMatrix[indexX][indexY]=1;
            tabla.DrawMark(indexX,indexY,isRed);
            raktak=true;
            isRed=!isRed;
        }
    }
}

void JatekMester::FiveInARow()
{
    int cMinus=0;
    int cPlus=0;
    int i=0;
    while(i<tablaMatrix.size() && cMinus<5 && cPlus<5){
        if(tablaMatrix[i][indexY]==-1) {++cMinus; cPlus=0;}
        else if(tablaMatrix[i][indexY]==1) {++cPlus; cMinus=0;}
        else if(tablaMatrix[i][indexY]==0) cMinus=cPlus=0;
        ++i;
    }
    if(cMinus>4 || cPlus>4) win=true;
}

void JatekMester::FiveInACol()
{
    int cMinus=0;
    int cPlus=0;
    int i=0;
    while(i<tablaMatrix.size() && cMinus<5 && cPlus<5){
        if(tablaMatrix[indexX][i]==-1) {++cMinus; cPlus=0;}
        else if(tablaMatrix[indexX][i]==1) {++cPlus; cMinus=0;}
        else if(tablaMatrix[indexX][i]==0) cMinus=cPlus=0;
        ++i;
    }
    if(cMinus>4 || cPlus>4) win=true;
}

void JatekMester::FiveInDiagonalSE()
{
    int cMinus=0;
    int cPlus=0;
    int x;
    int y;

    if(indexX==indexY) x=y=0;
    else if(indexX>indexY) {x=indexX-indexY; y=0;}
    else if(indexX<indexY) {x=0; y=indexY-indexX;}

    while(x<tablaMatrix.size() && y<tablaMatrix.size() && cMinus<5 && cPlus<5){
        if(tablaMatrix[x][y]==-1) {++cMinus; cPlus=0;}
        else if(tablaMatrix[x][y]==1) {++cPlus; cMinus=0;}
        else if(tablaMatrix[x][y]==0) cMinus=cPlus=0;
        ++x; ++y;
    }
    if(cMinus>4 || cPlus>4) win=true;
}

void JatekMester::FiveInDiagonalSW()
{
    int cMinus=0;
    int cPlus=0;
    int x=0;
    int y=0;

    if(indexX+indexY==tablaMatrix.size()-1) {x=tablaMatrix.size()-1; y=0;}
    else if(indexX+indexY<tablaMatrix.size()-1) {x=indexX+indexY; y=0;}
    else if(indexX+indexY>(tablaMatrix.size()-1)) {x=tablaMatrix.size()-1; y=indexY-((tablaMatrix.size()-1)-indexX);}

    while(x>-1 && y<tablaMatrix.size() && cMinus<5 && cPlus<5){
        if(tablaMatrix[x][y]==-1) {++cMinus; cPlus=0;}
        else if(tablaMatrix[x][y]==1) {++cPlus; cMinus=0;}
        else if(tablaMatrix[x][y]==0) cMinus=cPlus=0;
        --x; ++y;
    }
    if(cMinus>4 || cPlus>4) win=true;
}

void JatekMester::BeteltE()
{
    nemTeltBe=false;
    int i=0;
    while(i<tablaMatrix.size() && !nemTeltBe){
        int j=0;
        while(j<tablaMatrix.size() && !nemTeltBe){
            if(tablaMatrix[i][j]==0) nemTeltBe=true;
            ++j;
        }
        ++i;
    }
};

void JatekMester::StartAllapot()
{
    nemTeltBe=true;
    win=false;
    isRed=true;
    raktak=false;
}
