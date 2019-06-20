/***********************************************************
Name: Tomas Vasquez 
Assignment: 03
Purpose: This program functional doubly linked list class as described in class and in your text. Create a
linked list object from your class. This will require random data and numbers. g++ -I ./ *.cpp
***********************************************************/
#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;
struct Node
{
    int id;
    string data;
    Node *back;
    Node *forward;
};

class Items
{
    private:
    int count;
    Node *head;

    public: 
    Items();
    ~Items();
    bool addNode(int, string);
    bool deleteNode(int);
    //bool getNode(int, DataNode*);
    void printList(bool);
    int getCount();
    bool clear();
};

Items::Items()
{
    head = nullptr ;
}

Items::~Items()
{
    
}

bool Items::addNode(int x, string data)
{
    bool success = false;
    if (head ==NULL)
    {
        Node *tmp = new Node;
        tmp -> id = x;
        tmp -> data = data;
        tmp -> forward = NULL;
        tmp -> back = NULL;
        head = tmp;
        cout<<tmp -> id<<" "<<tmp -> data<<endl;
        //count++;
        success = true;
    }
    else 
    {


    }
    return success;

}

void Items::printList(bool)
{
    cout << head->id << endl;

}


int main()
{
    Items a;
    a.addNode(5, "t");
    //a.addNode(6, "t");
    //a.printList(a.addNode(1, "t"));
    



    return 0;
}