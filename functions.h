/***********************************************************
Name: Tomas Vasquez 
Assignment: 03
Purpose: This program adds/deletes to head, end, and middle data structure. Additionally, it puts every number in order. It prints out forward/backwards with parameters and forward without it.
It also retrieves any node. It will not insert duplicates or print out empty lists. First set are in order while the second half are randomly generated.
Notes:  I broke this down into several functions to take away multiple if statements. 
***********************************************************/
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
void deleteNodeAtGivenPos(int);
void deleteNode(struct Node* del); 

#endif

