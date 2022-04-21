#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

//Global Variables
const int ROWS = 50,
        COLS = 5;

typedef int Ans[ROWS][COLS];
typedef int Que[ROWS];

//Prototypes
void ruleSwitch();
void getQFromFile(Que [ROWS]);
void getAFromFile(Ans [ROWS][COLS]);
void game();

void start();
void line();
void error();



int main()
{
    start ();
    game ();
    return 0;
}


void start()
{
    ruleSwitch();
    line();
    cout << "Now, let's get the game started!";
//    getQFromFile(Question[][]);
}


void ruleSwitch()
{
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

    if (rules==1)
    {
        //Show Rule Function
    }
}


void getQFromFile(QueoneD)
{
    ifstream inFileQ;
    int count = 0;

    inFileQ.open("QuestionsInDatFile.dat");

    while(inFileQ)
    {
        getline(inFileQ, oneD[count]);
        count++;
    }
}

void getAFromFile(Ans woD)
{
    ifstream inFileA;

    inFileA.open("AnswersInDatFile.dat");

    for (int row = 0;  row < ROWS;  row++)
    {
		for (int col = 0; col < COLS;  col++)
		{
		    while(inFileA)
                getline(inFileA, twoD[row][col]);
		}
	}


}

void game()
{
    for(int counter = 1; counter <= 5; counter++)
    {
        srand(time(0));
        for(int s = 0; s <5; s++)
        {

            int c = 1+(rand()%maxN);

            cout << questions[c] << endl;
            cout << c << "\n\n\n";
        }
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
