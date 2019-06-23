//this is a directive that prevents .h files from being included more than once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include <iostream>
using namespace std;
#define SIZE 10


class Items
{
    private:
    Node *head;
    int count;

    public:
    Items();
    ~Items();
    bool push(int, string);
    int findSize();
    void bubbleSort();
    void printList(bool=true);
    void remove(int);
    bool getNode(int, DataNode*);

};

#endif //LINKEDLIST_H