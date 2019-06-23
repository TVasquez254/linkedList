#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "data.h"

using namespace std;

void fillData(DataNode**);
int range_random(int, int);
string random_string(int);
void printData(DataNode *d[]);
void bubbleSortData(DataNode**);
void swapData(int*, int*);

#endif

