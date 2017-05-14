#include <iostream>
#include "jatekmester.hpp"


const int XX=700;
const int YY=700;

int main()
{
    JatekMester jatekMester(XX, YY);
    jatekMester.EventCycle();

    return 0;
}
