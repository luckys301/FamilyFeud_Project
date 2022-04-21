#include <iostream>

using namespace std;

int RectArea(int, int);
double CircleArea(double, int);
int TriArea(int, int);
void display (int, double, int);

int main()
{
    int RArea, TArea;
    double CArea;

    cout << "Hello world!" << endl;
    RArea = RectArea(3, 5);
    CArea = CircleArea(3.14, 4);
    TArea = TriArea(2, 7);
    display (RArea, CArea, TArea);

    return 0;
}

int RectArea(int length, int width)
{
    return length * width;
}

double CircleArea(double pi, int r)
{
    return pi * r * r;
}

int TriArea(int b, int h)
{
    return (b*h)/2;
}

void display (int rect, double circle, int tri)
{
    cout << "The Area of the rectangle is " << rect << endl;
    cout << "The Area of the circle is " << circle << endl;
    cout << "The Area of the triangle is " << tri << endl;
}
