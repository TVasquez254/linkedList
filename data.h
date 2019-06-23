#ifndef DATA_H
#define DATA_H

#include <string>

#define DATA_SIZE 18
#define BUFFER_SIZE 12

using std::string;


typedef struct Node {
    int id;
    string data;
    Node* next;  
    Node* prev; 
} DataNode;

#endif
