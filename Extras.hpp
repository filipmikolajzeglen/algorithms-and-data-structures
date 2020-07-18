#pragma once
#ifndef Extras_hpp
#define Extras_hpp
#include <iostream>

using namespace std;

int* createSortedTable(int numbers);
int* createReverseSortedTable(int numbers);
int* createRandomSortedTable(int numbers);
void bestTime(double t1, double t2, double t3);
double averageTime(double t1, double t2, double t3);
void compareResultsOfSortedData(int numbers, string name);

#endif