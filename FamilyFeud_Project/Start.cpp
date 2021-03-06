#include <iostream>
#include<fstream>   //Used for Files Input/Output
#include<ctime>     //Used for rand()
#include<cstring>

//OUTPUT FILES
//Pass by reference
//
//sizeof
using namespace std;

//Global Variables
const int ROWS = 50,
        COLS = 3,
        MAXN = 50,
        QUENUM = 10;      //Number of questions in the Files

//Prototypes
void rules();
void start(string [ROWS], string [][COLS]);
    void getQFromFile(string [ROWS]);
    void getAFromFile(string [][COLS]);
int game(const string [ROWS], const string [][COLS]);
    int points(string, int, int&, const string [][COLS]);
    void highScore(int);
int bonus(const string [ROWS], const string [][COLS]);
    int bPoints(string, int, int&, const string [][COLS]);

void line();
void error();
void wrong();
void changeCase(string&);
int questionNum();

void input (int [QUENUM], int);

int main()
{
    string question[ROWS] = {"!"};         //How do I initialize all the things with a string
    string answer[ROWS][COLS] = {"I"};     //Initialize

    start(question, answer);
    int scoreM = game(question, answer);
    cout << "\nYour score for this game is " << scoreM;
    highScore(scoreM);

    if(scoreM > 50)
    {
        int scoreB = bonus(question, answer);
        cout << "\nYour score for this bonus round is " << scoreB;
    }

    return 0;
}


void start(string question [], string answer[][COLS])
{
    rules();
    line();

    getQFromFile(question);
    getAFromFile(answer);

    cout << "\nNow, let's get the game started!\n\n";
}


void rules()
{
    int rules = 0;
    cout << "\n\t\t\t\tWelcome to Friendly Feud\n";       //Family or Friendly Feud
    line();
    cout << "\n\t\t\t\tDo you want to review the rules?";
    cout << "\n\t\t\t\t1: Yes";
    cout << "\n\t\t\t\t2: No\n";

    cin >> rules;

    while (cin.fail() || (rules!=1 && rules!=2))
    {
        error();
        cin >> rules;
    }

    if (rules==1)
    {
        ifstream inRule;
        string rule;

        inRule.open("Rules.txt");

        if(!inRule)
        {
            cout << "\nThis program didn't open file 'Rules.txt'."
                << "\nThis program will end."
                << "\nTry running the program again.";
             exit(EXIT_SUCCESS);
        }

        while(inRule)
        {
            getline(inRule, rule);
            cout << rule << endl;
        }

        inRule.close();
    }
}

void getQFromFile(string oneD[ROWS])
{
    ifstream inFileQ;
    int c = 0;

    inFileQ.open("QuestionsInTxtFile.txt");

    if(!inFileQ)
    {
        cout << "\nThis program didn't open file 'QuestionsInDatFile.txt'."
            << "\nThis program will end."
            << "\nTry running the program again.";
         exit(EXIT_SUCCESS);
    }

    while(inFileQ && c < MAXN)
    {
        getline(inFileQ, oneD[c]);
        c++;
    }
    inFileQ.close();
}

void getAFromFile(string twoD [ROWS][COLS])
{
    ifstream inFileA;

    inFileA.open("AnswersInTxtFile.txt");

    if(!inFileA)
    {
        cout << "\nThis program didn't open file 'AnswersInDatFile.txt'."
            << "\nThis program will end."
            << "\nTry running the program again.";
         exit(EXIT_SUCCESS);
    }

    while(inFileA)
    {
        for (int row = 0;  row < ROWS;  row++)
        {
            for (int col = 0; col < COLS;  col++)
                getline(inFileA, twoD[row][col]);
        }
    }
    inFileA.close();
}

int game(const string questions [ROWS], const string answer[][COLS])
{
    int score = 0,
        q = 0,
        temp = 0;
    string inAnswer = "";
    srand(time(0));

    for(int c1 = 1; c1 <= 5; c1++)
    {
        q = questionNum();

        cout << "\n" << questions[q] << endl;

        cout << answer[q][0] << endl;
        cout << answer[q][1] << endl;
        cout << answer[q][2] << endl <<endl;

        cin >> inAnswer;
        changeCase(inAnswer);

        temp = points(inAnswer, q, score, answer);

        for(int c2 = 1; (temp!=1)&&c2<3; c2++)
        {
            cout << "\n" << questions[q] << endl;
            cin >> inAnswer;
            changeCase(inAnswer);
            temp = points(inAnswer, q, score, answer);
        }
        line();
    }
cout << score << endl;
    return score;
}

int points(string inA, int q, int&score, const string answer[][COLS])
{
    while(cin.fail() || !(inA == answer[q][0] || inA == answer[q][1] || inA == answer[q][2]))
        {
            wrong();
            cout << "\n+0";
            cout << "\nScore: " << score << endl;
            return 1;
        }

    if(inA== answer[q][0])
    {
        score+=10;
        cout << "\n+10";
        cout << "\nScore: " << score << endl;
        return 2;
    }

    else if(inA== answer[q][1])
        {
        score+=5;
        cout << "\n+5";
        cout << "\nScore: " << score << endl;
        return 2;
        }
    else if(inA== answer[q][2])
        {
        score+=1;
        cout << "\n+1";
        cout << "\nScore: " << score << endl;
        return 2;
        }
    else
        return 1;
}

void highScore(int score)
{
    ifstream inScore;
    int queAr [QUENUM] = {1};
    int q = 0;

    inScore.open("HighScore.dat");

    if(!inScore)
    {
        cout << "\nThis program didn't open file 'HighScore.dat'."
            << "\nThis program will end."
            << "\nTry running the program again.";
         exit(EXIT_SUCCESS);
    }

    while(inScore >> queAr[q] && q < QUENUM)
    {
//        getline(inScore, queAr[q]);
cout << "\nloop\n";
        q++;
    }

    inScore.close();

    for(int a =0; a<QUENUM; a++)
        cout << (a+1) << ". " << queAr[a] << endl;

    if(queAr[QUENUM-1] > score)
    {
        cout << "\nUnfortunately, your score isn't in the top ten.\nTry again next time.\n";
        exit(EXIT_SUCCESS);
    }

    if(queAr[QUENUM-1] < score)
    {
        input(queAr, score);
    }


}

void input (int score [QUENUM],int mScore)
{
    int temp = 0;

    for(int c=0; c < QUENUM; c++)
    {
        if(score[c] < mScore)
        {
            temp = score[c];
            score[c] = mScore;
        }
    }
    int n = 0;
    while(n < QUENUM)
    {
        cout << score[n] << endl;
        n++;
    }
}


void line()
{
    cout << "\n";
    for (int i = 0; i <= 39; i++)
        cout << "---";
//    cout << "\n";
}

void error()
{
    cin.clear();
    cin.ignore(100,'\n');   //Discards wrong input
    cout << "\t\t\t\tWrong Input. Try Again.\n";
}

void wrong()
{
    cout << "\t\t\t\tThat is the wrong answer. You recieve no points.\n";
}

void changeCase (string&example)
{

    int n = example.length();
    char str[n]; // declaring character array

    strcpy(str, example.c_str());   //Copies string to char array
    for (int i=0; i<n; i++)
    {
        if (str[i]>64 && str[i]<91)
            str[i] = str[i] + 32;       /*Converting uppercase characters to lowercase*/
    }
    example = "";   //Empties string
    for (int t = 0; t < n; t++)
        example = example + str[t];

}

int bonus (const string questions [ROWS], const string answer[][COLS])
{
    int choice = 0;
    string inAnswer = "";
    int bScore = 0;
    cout << "\nYou qualified for a bonus round!"
        << "\nDo you want play the bonus round?"
        << "\n1: Yes"
        << "\n2: No";
    cin >> choice;

    if(choice==2)
    {
        cout << "Thank You for playing the game!!";
        exit(EXIT_SUCCESS);
    }

    for(int counter = 1; counter<=2; counter++)
    {
        int q = questionNum();

        cout << "\n" << questions[q] << endl;

        cout << answer[q][0] << endl;
        cout << answer[q][1] << endl;
        cout << answer[q][2] << endl <<endl;

        cin >> inAnswer;
        changeCase(inAnswer);

        int temp = bPoints(inAnswer, q, bScore, answer);

        for(int c = 1; (temp!=1) && c<3; c++)
        {
            cout << "\n" << questions[q] << endl;
            cin >> inAnswer;
            changeCase(inAnswer);
            temp = bPoints(inAnswer, q, bScore, answer);
        }
        line();
    }
    return bScore;
}

int questionNum()
{
    static int loop = 1;
    static int p1, p2, p3, p4, p5, b1, b2 = 0;
    if(loop==1)
    {
        p1 = (rand()%(MAXN+1));
        p2 = (rand()%(MAXN+1));
        p3 = (rand()%(MAXN+1));
        p4 = (rand()%(MAXN+1));
        p5 = (rand()%(MAXN+1));

        b1 = (rand()%(MAXN+1));
        b2 = (rand()%(MAXN+1));

        while (p1 == p2 || p1 == p3 || p1 == p4 || p1 == p5 || p1 == b1 || p1 == b2)
            p1 = (rand()%(MAXN+1));

        while (p2 == p3 || p2 == p4 || p2 == p5 || p2 == b1 || p2 == b2)
            p2 = (rand()%(MAXN+1));

        while (p3 == p4 || p3 == p5 || p3 == b1 || p3 == b2)
            p3 = (rand()%(MAXN+1));

        while (p4 == p5 || p4 == b1 || p4 == b2)
            p4 = (rand()%(MAXN+1));

        while (p5 == b1 || p5 == b2)
            p5 = (rand()%(MAXN+1));

        while (b1 == b2)
            b1 = (rand()%(MAXN+1));
    }

    switch(loop)
    {
        case 1:
            loop++;
            return p1;
            break;
        case 2:
            loop++;
            return p2;
            break;
        case 3:
            loop++;
            return p3;
            break;
        case 4:
            loop++;
            return p4;
            break;
        case 5:
            loop++;
            return p5;
            break;
        case 6:
            loop++;
            return b1;
            break;
        case 7:
            loop++;
            return b2;
            break;
    }

    return 0;
}

int bPoints(string inA, int q, int&score, const string answer[][COLS])
{
    while(cin.fail() || !(inA == answer[q][0] || inA == answer[q][1] || inA == answer[q][2]))
        {
            wrong();
            cout << "\n+0";
            cout << "\nBonus Score: " << score;
            return 1;
        }

    if(inA== answer[q][0])
    {
        score+=10;
        cout << "\n+10";
        cout << "\nBonus Score: " << score;
        return 2;
    }

    else if(inA== answer[q][1])
        {
        score+=5;
        cout << "\n+5";
        cout << "\nBonus Score: " << score;
        return 2;
        }
    else if(inA== answer[q][2])
        {
        score+=1;
        cout << "\n+1";
        cout << "\nBonus Score: " << score;
        return 2;
        }
    else
        return 1;
}
