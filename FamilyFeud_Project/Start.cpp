#include <iostream>

using namespace std;

//Prototypes
int start();
void line();
void error();
void ruleSwitch(int);


int main()
{
    start ();

    return 0;
}


int start()
{
    //Variables
    int rules = 0;

    cout << "\t\t\t\tWelcome to Friendly Feud\n";       //Family or Friendly Feud
    line();
    cout << "\t\t\t\tDo you want to review the rules?\n";
    cout << "\t\t\t\t1: Yes\n";
    cout << "\t\t\t\t2: No\n";

    cin >> rules;

    while (cin.fail() || (rules!=1 && rules!=2))
    {
        error();
        cin >> rules;
    }

    line();
    ruleSwitch(rules);
}


void ruleSwitch(int rule)
{
    switch (rule)
    {
        case 1:
            //Show Rule Function
            break;
        case 2:
            break;
    }
}


void line()
{
    for (int i = 0; i <= 39; i++)
    {
        cout << "---";
    }
}


void error()
{
    cin.clear();
    cin.ignore(100,'\n');   //Discards wrong input
    cout << "\n\t\t\t\tYou have entered wrong input.\n";
}
