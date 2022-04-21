#include <iostream>
//#include "calcs.h"
#include "calculations.cpp"
//#include "display.h"
#include "display.cpp"

using namespace std;


int main()
{
    int RArea, TArea;
    double CArea;

    cout << "Welcome to MultiSource File Practice!" << endl;

    RArea = RectArea(3, 5);
    CArea = CircleArea(3.14, 4);
    TArea = TriArea(2, 7);
    display (RArea, CArea, TArea);

    return 0;
}

