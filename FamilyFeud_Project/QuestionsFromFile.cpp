#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

//typedef int question [50];

int main()
{
    ifstream inFile;
    string questions [50];
    int count =0;

    int maxN = 12;
    int minN = 0;

    inFile.open("Questions.dat");

    while(inFile)
    {
        //inFile >> questions[count];
        getline(inFile, questions[count]);
        count++;
    }

    srand(time(0));
    for(int s = 0; s <5; s++)
    {

    int c = 1+(rand()%maxN);

    cout << questions[c] << endl;
    cout << c << "\n\n\n";
    }

    /*for(int c = 0; c<count; c++)
    {

        cout << questions[c] << endl;
    }*/
}
