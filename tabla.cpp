#include "tabla.hpp"
#include <cstdlib>

using namespace genv;


Tabla::Tabla(int posX_, int posY_, int width_, int height_) : Widget(posX_, posY_)
{
    width=width_;
    height=height_;

    colWidth=width/20; //KESOBBI FAZISBAN MAJD: NUMBOXTOL ELKER, SZAMOLAS ATALAKIT
    lineHeight=height/20; //KESOBBI FAZISBAN MAJD: NUMBOXTOL ELKER, SZAMOLAS ATALAKIT
}

void Tabla::Handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left){
        clickPosX=ev.pos_x;
        clickPosY=ev.pos_y;
    }
}

int Tabla::CalcIndexX()
{
    int returnValue;
    div_t divResult=div(clickPosX,colWidth);
    if(divResult.rem=0) returnValue=-1;
    else returnValue=divResult.quot;
    return returnValue;
}

int Tabla::CalcIndexY()
{
    int returnValue;
    div_t divResult=div(clickPosY,lineHeight);
    if(divResult.rem=0) returnValue=-1;
    else returnValue=divResult.quot;
    return returnValue;
}

int Tabla::CalcDrawPosX(int IndexX)
{
    return IndexX*colWidth;
}

int Tabla::CalcDrawPosY(int IndexY)
{
    return IndexY*lineHeight;
}


void Tabla::Draw()
{
    gout<<color(colorBgr.r,colorBgr.g,colorBgr.b)<<move_to(0,0)<<box(width,height);

    gout<<color(colorFrm.r,colorFrm.g,colorFrm.b);
    for(int i=0; i<=width; i+=colWidth){
        gout<<move_to(i,0)<<line(0,height);
    }
    for(int i=0; i<=height; i+=lineHeight){
        gout<<move_to(0,i)<<line(width,0);
    }
}

void Tabla::DrawMark(int IndexX, int IndexY, bool isRed)
{
    if(isRed) gout<<color(255,70,70);
    else gout<<color(70,70,255);
    gout<<move_to(CalcDrawPosX(IndexX),CalcDrawPosY(IndexY))
        <<move(1,1)<<box(colWidth-1,lineHeight-1);
}
