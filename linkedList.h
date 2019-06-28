/***********************************************************
Name: Tomas Vasquez 
Assignment: 03
Purpose: This program adds/deletes to head, end, and middle data structure. Additionally, it puts every number in order. It prints out forward/backwards with parameters and forward without it.
It also retrieves any node. It will not insert duplicates or print out empty lists. First set are in order while the second half are randomly generated.
Notes:  I broke this down into several functions to take away multiple if statements. 
***********************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include <iostream>
using namespace std;
//#define SIZE 10


class Items
{
    private:
    Node *head;
    int count;
    

    public:
    Items();
    ~Items();
    bool addNode(int, string);
    int getCount();
    void printList(bool=true);
    bool deleteNode(int);
    bool getNode(int, DataNode*);
    bool clear();
    bool search(int);

};

#endif //LINKEDLIST_H