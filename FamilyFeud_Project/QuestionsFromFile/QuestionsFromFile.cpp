#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

//typedef int question [50];
void questionCheck(int&);
bool compareNum(const vector<int>&, int);

//Global Variable
const int maxN = 12;
const int minN = 0;

int main()
{
    ifstream inFile;
    int questionSize= 50;
    string questions [questionSize];
    int count =0;

    inFile.open("QuestionsinDatFile.dat");
    while(inFile && count <= 50)
    {
        getline(inFile, questions[count]);
        count++;
    }
    inFile.close();

    srand(time(0));
    for(int s = 0; s <5; s++)
    {

    int c = 1+(rand()%maxN);
    questionCheck(c);

    cout << questions[c] << endl;
    cout << c << "\n\n\n";
    }
}


void questionCheck(int&q)
{
    vector <int> questions;
    while(!(compareNum(questions, q)))
    {
        q = rand()%maxN;
    }
    questions.push_back(q);
}


bool compareNum(const vector<int>& ar, int num)
{
    int sizeOfAr = ar.size();
    cout << sizeOfAr;
//    for(int com = 0; com < sizeOfAr; com++)
//    {
//        cout << com;
////        if (num == ar[com])
////        {
////            cout << "num == ar[com]";
////            return true;  //Returns True
////        }
////        else
////        {
////            cout << "else";
////            return false;  //Returns False
////        }
//    }

//return true;
}
