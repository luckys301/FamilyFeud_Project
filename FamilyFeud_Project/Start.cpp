#include <iostream>

using namespace std;

int start()
{
    //Variables
    int rules = 1;

    cout << "Welcome to (Family Fued)\n";
    cout << "Do you want to review the rules?\n";
    cout << "1: Yes\n";
    cout << "2: No\n";

    cin >> rules;
    switch (rules)
    {
        case 1:
            //Show Rule Function
            break;
        case 2:
            break;
        default:
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error. Do you want to review the rules?\n";
            cout << "1: Yes\n";
            cout << "2: No\n";
    }

}

int main()
{
    start ();
}
