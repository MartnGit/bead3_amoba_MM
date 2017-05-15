#include "startmenu.hpp"

using namespace genv;


StartMenu::StartMenu(int posX_, int posY_, int width_, int height_) : Widget(posX_, posY_)
{
    width=width_;
    height=height_;
}

void StartMenu::Draw()
{
    gout<<color(200,200,200)<<move_to(0,0)<<box(width,height);
    gout<<color(0,0,0)<<move_to(50,200)
        <<text("Klasszikus 20x20 zartpalyas amoba jatek, 5 egyformat kell kirakni egymas melle.\nKetszemelyes jatek, egyszer az egyik jatekos lep, majd a masik.\n\n")
        <<text("A jatek soran a bal egergombbal lehet rakni.\nAmennyiben valaki nyert, betelt a palya vagy elfogytak a lepesek,\na Space billentyuvel indithato ujra a jatek.\nKilepes a jatekbol az Escape billentyuvel.\n\n")
        <<text("A szamlalo segitsegevel allitsa be a jatekosonkenti maximalis lepesszamot.\nHasznalhatja a fol-le nyilakat es a PageUp, PageDown billentyuket is.\nEzutan nyomja meg az Enter billentyut a jatek inditasahoz.\n\n")
        <<refresh;
}
