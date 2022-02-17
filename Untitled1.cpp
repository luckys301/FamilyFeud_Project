/*Sai Varshini Chinnasani
Course: COSC 1436.001 Programming Fundamentals
Lab #2: Converts Celsius to Fahrenheit
Due Date: February 13, 2022
Instructor: Korinne Caruso

Purpose: The purpose of this program is to convert from Celsius
    to Fahrenheit or Fahrenheit to Celsius.

Input: The main input for this program is the Celsius in degrees.
    There are also going to be instances where the user will have
    to type a 1 or 2 to make a decision to reloop the calculator.
    All the inputs from this program are from the user.

Output: There are many different outputs for this program. They
    include instructions and the conversion of the user's temp-
    erature. The output is sent out to the user using cout.

Extra Info for future Use: The user for this program is anyone
who wants to convert from Celsius to Fahrenheit. The setw() to
set the number of character spaces to use for the following phrase.*/

//Used for cin and cout
#include <iostream>
//Used for formatting output
#include <iomanip>

using namespace std;

int main()
{
    //Local Variables
    double celsius = 0;
    double fahrenheit = 0;
    //Used for a decision by user
    //This is initialized as 1, so the while statement in the do while loop is true, so it runs the do statement
    int choice = 1;
    //This is used to choose a calculator
    int conversion =1;


    //Describing what this program does
        cout << endl << "This calculator converts degrees from Celsius to Fahrenheit or Fahrenheit to Celsius."<< endl << endl;


    //Do While Loop
    do
    {
        cout << endl << "Do you want to convert from Celsius to Fahrenheit or Fahrenheit to Celsius?" << endl;
        cout << setw(40) << "Enter 1 for Celsius to Fahrenheit" << endl;
        cout << setw(40) << "Enter 2 for Fahrenheit to Celsius" << endl;
        //Input of conversion
        cin >> conversion;

        while (cin.fail() || 0>conversion || conversion>3)
        {
            cin.clear();
            //Discards wrong input
            cin.ignore(100,'\n');
            cout << endl << setw(70) << "You have entered wrong input."<<endl;
            cout << setw(70) << "Reenter '1' or '2'." << endl;
            cin >> conversion;
        }



        //If user wants C to F, this is executed
        if (conversion == 1)
        {
            //Asking user for the degrees in Celsius
            cout << endl << "What is the degrees in Celsius?" << endl;
            cout << "   Put the answer in numerical value (ex: 5), then press enter" << endl;
            //Input of Celsius
            cin >> celsius;

            //If the Input is bad, it clears the value and asks you to reenter value for Celsius
            while(cin.fail())
            {
                cin.clear();
                //Discards wrong input
                cin.ignore(100,'\n');
                cout << endl << setw(70) << "You have entered wrong input."<<endl;
                cout << setw(70) << "Reenter numerical value (ex: 5), then press enter." << endl;
                cin >> celsius;
            }

            //Calculation for Fahrenheit: (C × 9)/5 + 32 = F
            fahrenheit = (celsius * 9)/5 + 32;

            //Output for Fahrenheit
            cout << endl << celsius << " degree(s) in Celsius is " << fahrenheit << " degree(s) in Fahrenheit." << endl << endl << endl;
        }
        //If user wants F to C, this is executed
        else if (conversion == 2)
        {
            //Asking user for the degrees in Fahrenheit
            cout << endl << "What is the degrees in Fahrenheit?" << endl;
            cout << "   Put the answer in numerical value (ex: 5), then press enter" << endl;
            //Input of Fahrenheit
            cin >> fahrenheit;

            //If the Input is bad, it clears the value and asks you to reenter value for Fahrenheit
            while(cin.fail())
            {
                cin.clear();
                //Discards wrong input
                cin.ignore(100,'\n');
                cout << endl << setw(70) << "You have entered wrong input."<<endl;
                cout << setw(70) << "Reenter numerical value (ex: 5), then press enter." << endl;
                cin >> fahrenheit;
            }

            //Calculation for Fahrenheit: (F - 32) * 5/9 = C
            celsius = (fahrenheit - 32) * 5/9;

            //Output for Fahrenheit
            cout << endl << fahrenheit << " degree(s) in Fahrenheit is " << celsius << " degree(s) in Celsius." << endl << endl << endl;
        }



        //Instructions for Prompt
        cout << "Do you want to reuse the calculator?" << endl;
        cout <<  setw(70) << "Type in '1' to redo calculation." << endl;
        cout <<  setw(70) << "Type in '2' to stop calculation. This ends the program." << endl;
        //Input of Prompt Answer (choice)
        cin >> setw(2) >> choice;

        //If an integer is not inputed, or an integer that is less
        //than 0 or more than 2 is, it will ask user to reenter choice
        while (cin.fail() || 0>choice || choice>3)
        {
            cin.clear();
            //Discards wrong input
            cin.ignore(100,'\n');
            cout << endl << setw(70) << "You have entered wrong input."<<endl;
            cout << setw(70) << "Reenter '1' or '2'." << endl;
            cin >> choice;
        }

        //If user chooses to end the calculator, this happens
        if (choice == 2)
        {
             cout << "Thank You for using this calculator!";
            return 0;
        }
    }
    //If choice still equals to 1, the program will reloop.
    while (choice == 1);
}
