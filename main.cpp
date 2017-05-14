#include <iostream>
#include "jatekmester.hpp"

using namespace std;


const int XX=500;
const int YY=500;

int main()
{
    JatekMester jatekMester(XX,YY);
    jatekMester.EventCycle();

    return 0;
}
