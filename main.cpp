/***********************************************************
Name: Tomas Vasquez 
Assignment: 03
Purpose: This program adds/deletes to head, end, and middle data structure. Additionally, it puts every number in order. It prints out forward/backwards with parameters and forward without it.
It also retrieves any node. It will not insert duplicates or print out empty lists. First set are in order while the second half are randomly generated.
Notes:  I broke this down into several functions to take away multiple if statements. 
***********************************************************/
#include "main.h"


int main() {
    //***************************************************
    //      Main Data test                              *
    //***************************************************
    srand(time(NULL));
    int num_tests = rand() % (TEST_CASE_BASE-1)+1;  //Generates random data
    int RANDOM = rand() % (num_tests);      //Generates random data for first while loop
    int SIZE1=0;                          //counter control variable
    int x,y;

    Items items;
    DataNode *d[DATA_SIZE];
    
    fillData(d);
    bubbleSortData(d);
    printData(d);
    cout << endl;
    cout<<"Num test "<<num_tests<<endl;
    items.clear();
    items.deleteNode(d[num_tests]->id);                     // Cant delete from head 
    items.addNode(d[num_tests]->id, d[num_tests]->data);   //Adding to head
    
    cout<<"Node/Clear test"<<endl;
    for(x = 0; x<RANDOM; x++) 
    {
        for(y = 0; y<x ; y++)
        {
            items.addNode(d[num_tests]->id, d[num_tests]->data);
        }
            items.clear();
            cout<<"List cleared"<<endl;
            cout<<endl;  
   }
    items.printList(true);  //Printing list
    items.clear();
    cout<<"Deleting a number not on list"<<endl;
    items.deleteNode(d[RANDOM]->id); 
    cout<<endl;

    //***************************************************
    //  Testing adding multiple var at diff points      *
    //***************************************************
    cout<<"Testing adding multiple variables"<<endl;                                        
     while (SIZE1<RANDOM)
     {
         int second_tests = rand() % (num_tests);    // Randomizing the linked list
         items.addNode(d[second_tests]->id, d[second_tests]->data);
         SIZE1++;
     }

    cout<<"Print Forward"<<endl;
    items.printList(true);  //Printing forward list 
    cout<<endl;
    cout<<"Print backwards"<<endl;
    items.printList(false);  //Printing backwards list 
    cout<<endl;
    cout<<"The size of linked list: "<<items.getCount()<<endl;
    items.clear();
    items.printList();  //Printing list after deletion
    cout<<"The size of linked list: "<<items.getCount()<<endl;
    cout<<endl;


    //***************************************************
    //      GetNode Data test                           *
    //***************************************************
    items.addNode(d[num_tests]->id, d[num_tests]->data);
    DataNode *singleNode = new DataNode;            //Empty DataNode

    cout<<"GetNode test"<<endl;  
    if(items.getNode(d[num_tests]->id, singleNode))
    {
        cout << "Node Found" << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }
    cout << "ID: " << singleNode->id << endl;
    cout << "Data: " << singleNode->data << endl;
    cout<<endl;
    if(items.getNode(19, singleNode))
    {
        cout << "Node found" << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }
    cout << "ID: " << singleNode->id << endl;
    cout << "Data: " << singleNode->data << endl;


    cout<<endl;
    cout<<endl;

    //***************************************************
    //      Testing for project                         *
    //***************************************************
    cout << "Making " << num_tests << " test cases..." << endl;
    cout<< "Position: "<<num_tests<<endl;
    cout<<endl;


    cout<<d[num_tests]->id<<" : "<<d[num_tests]->data<<endl;
    items.addNode(d[num_tests]->id, d[num_tests]->data);
    cout<<"The size of linked list: "<<items.getCount()<<endl;
    items.printList();
    items.clear(); 
    items.printList();
    cout<<"The size of linked list: "<<items.getCount()<<endl;
    cout<<endl;


    //***************************************************
    //      Testing under random conditions             *
    //***************************************************

    cout<<"Random conditions being tested for failure"<<endl;
    int a = 1;                   // Local variable counter declaration an intial condition for the loop    
    while (a<num_tests)         // while loop execution and test condition
    {
        cout<<endl;
        int selection = rand() % 7+1;
        int third_tests = rand() % (num_tests);    // Randomizing the linked list 

        switch(selection) 
        {
            case 1 :
            cout<<"Count"<<endl;
            cout<<"The size of linked list: "<<items.getCount()<<endl;
            break;

            case 2 :
            cout<<"Add element"<<endl;
            items.addNode(d[num_tests]->id, d[third_tests]->data);
            break;

            case 3 :
            cout<<"Remove element"<<endl;
            items.deleteNode(d[third_tests]->id);
            break;

            case 4:
            cout<<"Clear list"<<endl;
            items.clear();
            break;

            case 5:
            cout<<"GetNode"<<endl;
            if(items.getNode(d[third_tests]->id, singleNode))
                {
                    cout << "Node Found" << endl;
                }
            else
                {
                    cout << "node not found" << endl;
                }
                cout << "ID: " << singleNode->id << endl;
                cout << "Data: " << singleNode->data << endl;
            break;

            case 6:
            cout<<"Print List Forward"<<endl;
            items.printList();
            break;

            case 7:
            cout<<"Print List Reversed"<<endl;
            items.printList(false);
            break;

        }
        a++;  
    } //end Switch statement 

    return 0;
}

