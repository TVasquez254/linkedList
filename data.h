/***********************************************************
Name: Tomas Vasquez 
Assignment: 03
Purpose: This program adds/deletes to head, end, and middle data structure. Additionally, it puts every number in order. It prints out forward/backwards with parameters and forward without it.
It also retrieves any node. It will not insert duplicates or print out empty lists. First set are in order while the second half are randomly generated.
Notes:  I broke this down into several functions to take away multiple if statements. 
***********************************************************/
#ifndef DATA_H
#define DATA_H

#include <string>

#define DATA_SIZE 30
#define BUFFER_SIZE 12

using std::string;


typedef struct Node {
    int id;
    string data;
    Node* forward;  
    Node* back; 
} DataNode;

#endif
