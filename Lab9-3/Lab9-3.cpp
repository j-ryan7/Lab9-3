/*
Jaden Ryan
4/2/2026

Program Description: a way to simulate dice rolls, and generate parantheses when 
sequential rolls output the same numbers
*/
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayRun(int values[], int size);    //This function takes the array values, and prints them out while returning nothing
bool hasRun(int values[], int size);        //This boolean checks if there is a run in the array, and returns true if there is one

int main() {
    srand(time(0));                 //This sets so the dice rolls are different for each generation

    const int ARRAYSIZE = 20;       //This sets the array size equal to 20 per the assignment request
    int numbers[ARRAYSIZE];         //This sets the array with a number of elements equal to the array size, which is 20
    bool run = true;        //This operator stores the value of hasRun

    for (int i = 0; i < ARRAYSIZE; i++)     //This for loop generates all of the random numbers and stores them in the array
    {
        numbers[i] = rand() % 6 + 1;      //This makes sure all values are between 1 and 6, as 0 isn't a valid result
    }
    run = hasRun(numbers, ARRAYSIZE);       //This runs the function and returns a true or false value
    if (run == true) {                  //If there is a run, the function is true, so we output that there is a run
        cout << "has run: ";
    }
    else {                      //Otherwise it's false, so we output there is no run
        cout << "no run: ";
    }
    displayRun(numbers, ARRAYSIZE);     //This runs the function displayRun. Since it's a void function, it just prints things,
                                        //so no value needs returned or stored
    return 0;
}

void displayRun(int values[], int size){     //This function runs with the array and the array size
    bool inRun = false;     //This stores whether or not it is currently in a run

    for (int i = 0; i < size; i++){      //This for loop runs through every value of the array
        if (values[i] == values[i + 1]){         //This checks if the current index value is equal to the one above it
            if (inRun == false)                 //If the values are equal, then we check if we're in a run. 
            {
                cout << "(";                    //If we're not in a run, we need to start it, so we put parantheses
                inRun = true;                   //This then sets inRun to true, otherwise it would print left parantheses repeatedly
            }
        }
        else{               //If they aren't equal, this runs
            if (inRun){             //If we're currently in a run, and the next value would end the run,
                cout << values[i] << ") ";      // output a right parantheses to mark the end of the run
                inRun = false;          //Set inRun back to false so the previous if statements work like they should
                continue;           //This skips past the cout line following this, but doesn't fully break the loop like "break;" would
            }
        }
        cout << values[i] << " ";       //If a value and a right parantheses wasn't printed, then it needs printed, and this does it.
    }
}

bool hasRun(int values[], int size){             //This runs with the array and the array size to see if there is runs present
    for (int i = 0; i < size - 1; i++){          //This checks all values of the array, excluding the final one. Otherwise it would try to compare it to a nonexistent element.
        if (values[i] == values[i + 1]){         //If a value is equal to the value immediately above it, then it returns true.
            return true;
        }
    }
    return false;       //If it makes it here, there's no run, so it returns false.
}

