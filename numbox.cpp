#include "numbox.hpp"

using namespace genv;


NumBox::NumBox(int posX_, int posY_, int numMin_, int numMax_) : Widget(posX_, posY_), numMin(numMin_), numMax(numMax_), num(numMin_)
{
    width=100;
    height=50;

    relPosBtnUpX=relPosBtnDwnX=width/3*2;
    relPosBtnUpY=0;
    relPosBtnDwnY=height/2;

    relPosPlusX=relPosMinusX=relPosBtnUpX+(width-relPosBtnUpX)/2;
    relPosPlusY=relPosBtnUpY+relPosBtnDwnY/2;
    relPosMinusY=relPosBtnDwnY+(height-relPosBtnDwnY)/2;

    relPosNumX=relPosBtnUpX/2;
    relPosNumY=height/2;

    isFocused=false;
}

void NumBox::Draw()
{
    if(isActive)
    {
            std::string stringNum;
        stringNum=StringNum(num);

        if(!isFocused) gout<<color(colorBgr.r,colorBgr.g,colorBgr.b); //háttér
        else gout<<color(colorSelected.r,colorSelected.g,colorSelected.b);
        gout<<move_to(posX,posY)
            <<box(width,height);

        gout<<color(colorFrm.r,colorFrm.g,colorFrm.b) //keret
            <<move_to(posX,posY)
            <<line(width,0)<<line(0,height)<<line(-width,0)<<line(0,-height)
            <<move(relPosBtnUpX,relPosBtnUpY)<<line(0,height)<<move_to(posX,posY)<<move(relPosBtnDwnX,relPosBtnDwnY)<<line(width-relPosBtnDwnX,0)

            <<color(colorBtn.r,colorBtn.g,colorBtn.b) //gombok
            <<move_to(posX,posY)<<move(relPosPlusX-gout.twidth("+")/2,relPosPlusY+gout.cascent()/2)<<text("+")
            <<move_to(posX,posY)<<move(relPosMinusX-gout.twidth("-")/2,relPosMinusY-gout.cdescent()/2)<<text("_")

            <<color(colorFont.r,colorFont.g,colorFont.b) //szám
            <<move_to(posX,posY)<<move(relPosNumX-gout.twidth(stringNum)/2,relPosNumY+gout.cascent()/2)<<text(stringNum)

            <<refresh;
    }

}

void NumBox::Handle(event ev)
{
    if(isActive)
    {
        if(ev.type==ev_mouse && ev.button==btn_left){
            if(ev.pos_x>=posX && ev.pos_x<=posX+width  &&  ev.pos_y>=posY && ev.pos_y<=posY+height){
                isFocused=true;
                if(ev.pos_x>posX+relPosBtnUpX){
                         if(ev.pos_y<posY+relPosBtnDwnY && num<numMax) num+=1;
                    else if(ev.pos_y>posY+relPosBtnDwnY && num>numMin) num-=1;
                }
            }
            else isFocused=false;
        }

        else if(ev.type==ev_key && isFocused){
                 if(ev.keycode==key_up && num<numMax) num+=1;
            else if(ev.keycode==key_down && num>numMin) num-=1;
            else if(ev.keycode==key_pgup){
                    if(num<=numMax-10) num+=10;
                    else num=numMax;
            }
            else if(ev.keycode==key_pgdn){
                    if(num>=numMin+10) num-=10;
                    else num=numMin;
            }
        }
    }

}

std::string NumBox::StringNum(int num)
{
    std::stringstream ssNum;
    std::string stringNum;
    ssNum<<num;
    ssNum>>stringNum;
    return stringNum;
}
