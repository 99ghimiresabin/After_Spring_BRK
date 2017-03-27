/*
 * UtilitiesClass.hpp
 *
 *  Created on: Mar 6, 2017
 *      Author: sabinghimire
 */
#include <iostream>
#include <vector>

#ifndef UTILITIESCLASS_HPP_
#define UTILITIESCLASS_HPP_
using namespace std;
class UtilitiesClass {
public:
	UtilitiesClass();
static	string makeUpperCase(string);
static	string makeLowerCase(string);
static	void clearCIN(void);
static	string inputString(string, int, int);
static	int inputInt(string, int, int, int);
static	double inputDouble(string, double, double, double);
static	string centerString(string, int);
static	int getRandomInt(int, int);
static	double getRandomDouble(int, int, int);
static	bool verifyAction(string);
static	char askOverWrite(void);
static	string getRandomString(int, int);
static	int binarySearch(vector<int> aVector, int numElems, int value);/// BINARY SEARCH
static	void BubbleSort(vector<int> aVector, int size);// BUBBLE SORT
static	void selectionSort(vector<int> aVector, int size) ;///SELECTION SORT
static	int linearSearch(vector<int> aVector , int numElems, int value); /// LINEAR SEARCH

private :




	virtual ~UtilitiesClass();
};

#endif /* UTILITIESCLASS_HPP_ */
