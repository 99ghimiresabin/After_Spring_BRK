//============================================================================
// Name        : UtilitiesClass.cpp
// Author      : Sabin Ghimire
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "UtilitiesClass.hpp"
#include <math.h>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

//
//This routine will take a string and convert it to upper case
//Since a string is basically an array of char values, the string
//passed in will be processed one character at a time making each
//character upper-case
//
string UtilitiesClass::makeUpperCase(string theString) {

    locale settings;
    string newString;

    for(short i = 0; i < theString.size(); ++i)
        newString += (toupper(theString[i], settings));

    return newString;

}//makeUpperCase

//
//This routine will take a string and convert it to lower case
//Since a string is basically an array of char values, the string
//passed in will be processed one character at a time making each
//character lower-case
//
string UtilitiesClass::makeLowerCase(string theString) {

    locale settings;
    string newString;

    for(short i = 0; i < theString.size(); ++i)
        newString += (tolower(theString[i], settings));

    return newString;

}//makeUpperCase

//
//Clear the CIN input buffer to avoid problems
//
void UtilitiesClass::clearCIN(void) {
    cin.clear();
    cin.ignore(32768, '\n');
    return;
}//clearCIN

//
//Input a string to be returned to the calling function.
//
string UtilitiesClass::inputString(string promptString, int minLength, int maxLength) {
    string userInput;

    while (true) {
        cout << promptString << "\n";
        getline(cin, userInput);
        if (userInput.size() < minLength || userInput.size() > maxLength) {
            cout << "The string you entered is too short or too long.  Should be " << minLength << " to " << maxLength << " in Length\n";
            cout << "Please try again\n";
        }//if
        else
            break;
    }//while
    return userInput;
}//inputString

//
//Input a integer value to be returned to the calling function.  Also, validate the
//the minimum and maximum value of the integer input.
//
int UtilitiesClass::inputInt(string promptString, int minValue, int maxValue, int exitValue) {
    int userInput;

    cout << promptString << " \n";
    while (true) {
        cin >> userInput;
        if (!cin.fail()) {
            char myChar = cin.peek();
            if (myChar == '\n')
                if ((userInput >= minValue && userInput <= maxValue) || userInput == exitValue)
                    break;
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
        }//if
        else {
            cout << "Invalid integer value entered. Please try again.\n";
            clearCIN();
        }//else
    }
    clearCIN();
    return userInput;
}//inputInt

//
//Input a double value to be returned to the calling function.  Also, validate the
//the minimum and maximum value of the double input.
//
double UtilitiesClass::inputDouble(string promptString, double minValue, double maxValue, double exitValue) {
    double userInput;

    cout << promptString << " \n";
    while (true) {
        cin >> userInput;
        if (!cin.fail()) {
            char myChar = cin.peek();
            if (myChar == '\n')
                if ((userInput >= minValue && userInput <= maxValue) || userInput == exitValue)
                    break;
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
                else {
                    cout << "Invalid value entered.  Should be between " << minValue << " and " << maxValue << " Please try again\n";
                    clearCIN();
                }//else
        }//if
        else {
            cout << "Invalid double value entered. Please try again.\n";
            clearCIN();
        }//else
    }
    clearCIN();
    return userInput;
}//inputdouble

//
//Send a string and center it in a returned string
//
string UtilitiesClass::centerString(string stringToCenter, int toWidth)
{
    string outputString;
    int l = 0;
    int pos = 0;

    l = static_cast<int>(stringToCenter.length());
    pos=(toWidth-l)/2;
    for(int i=0;i<pos;i++) {
        outputString = outputString + " ";
    }//for
    outputString = outputString + stringToCenter;
    return outputString;
}//centerString

//
// This function will return a random integer no larger than Max
//
int UtilitiesClass::getRandomInt(int Min, int Max) {
    int tempInt = 0;

    while (true) {
        tempInt = rand() % Max;
        if (tempInt >= Min)
            break;
        else {}
    }//while

    return tempInt;
}//getRandomInt

//
//This function will return a random double with 2 decimal digits, and not greater than Max
//
double UtilitiesClass::getRandomDouble(int Min, int Max, int decimalPlaces) {
    double returnNum;
    int tempInt;
    double tempDouble;

    while (true) {
        returnNum = ((double)rand()/RAND_MAX);
        tempInt = (returnNum * Max)*(pow(10, decimalPlaces));
        tempDouble = static_cast<double>(tempInt)/(pow(10, decimalPlaces));
        if (tempDouble >= Min)
            break;
        else {}
    }//while
    return tempDouble;
}//getRandomDouble

//
// This function will return a random integer no larger than Max
//
string UtilitiesClass::getRandomString(int Min, int Max) {
    string tempString;

    int size = getRandomInt(Min, Max);
    for (int ctr=0; ctr<size; ctr++) {
        char tempChar = getRandomInt(97, 122);
        tempString += tempChar;
    }//for

    return tempString;
}//getRandomInt

//
//Display a prompt asking the user if they want to
//sort the vector ascending or descening.
//
bool UtilitiesClass::verifyAction(string userPrompt) {
    char userInput;
    bool returnValue = false;

    while (true) {
        cout << "\n";
        cout << userPrompt << "\n";
        cout << "<Y>es, <N>o ==> ";
        cin >> userInput;
        if (toupper(userInput) == 'Y') {
            returnValue = true;
            break;
        }//if
        else if (toupper(userInput) == 'N') {
            returnValue = false;
            break;
        }//else if
        else {
            cout << "Invalid selection, please try again\n";
        }//else
        clearCIN();
    }//while

    clearCIN();
    return returnValue;
}//verifyAction

//
//Ask the user if they want to append, overwrite or quit the read operation
//
char UtilitiesClass::askOverWrite(void) {
    char userChoice;

    cout << "You already have data loaded into the system\n";
    cout << "Do you want to (O)verwrite, (A)ppend or (Q)uit? ";
    cin >> userChoice;
    switch (toupper(userChoice)) {
        case 'O': {
            break;
        }//case O
        case 'A':
            break;
        case 'Q':
        default: {
            cout << "Operation Aborted\n";
            return 'Q';
        }//default
    }//switch

    return toupper(userChoice);

}//askOverwrite


/// sorts

int UtilitiesClass::binarySearch(vector<int> aVector, int numElems, int value) {
	int first = 0;
	int last;
	last = (numElems - 1);
	int middle;
	int position;
	position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (aVector[middle] == value) {
			found = true;
			position = middle;
		}

		else if (aVector[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

void UtilitiesClass::BubbleSort(vector<int> aVector, int size) {
	bool swap;
	int temp;
	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (aVector[count] > aVector[count + 1]) {
				temp = aVector[count];
				aVector[count] = aVector[count + 1];
				aVector[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void UtilitiesClass::selectionSort(vector<int> aVector, int size) {
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = aVector[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (aVector[index] < minValue) {
				minValue = aVector[index];
				minIndex = index;
			}
		}
		aVector[minIndex] = aVector[startScan];
	aVector[startScan] = minValue;
	}
}

int UtilitiesClass::linearSearch(vector<int> aVector , int numElems, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;
	while (index < numElems && !found)
	{
			if (aVector[index] == value)
			{
			found = true; position = index;
			}
			index++;
	}
	return position;
}


























//
//UtilitiesClass::UtilitiesClass() {
//	// TODO Auto-generated constructor stub
//
//}
//
//
//UtilitiesClass::~UtilitiesClass() {
//	// TODO Auto-generated destructor stub
//}


