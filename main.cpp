
#include "main.h"


int main() {

    //***************************************************
    //      Main Data test                              *
    //***************************************************
    srand(time(NULL));
    int num_tests = rand() % (TEST_CASE_BASE + 1);
    int RANDOM = rand() % (num_tests);
    int SIZE1=0;                          //counter control variable
    Items items;
    DataNode *d[DATA_SIZE];
    

    fillData(d);
    bubbleSortData(d);
    printData(d);
    cout << endl;

    items.clear();
    items.remove(d[num_tests]->id);                     // Cant delete from head 
    items.push(d[num_tests]->id, d[num_tests]->data);   //Adding to head
    items.printList(true);  //Printing list 
    cout<<"Deleting a number not on list"<<endl;
    items.remove(d[RANDOM]->id); 
    cout<<endl;

    //***************************************************
    //  Testing adding multiple var at diff points      *
    //***************************************************
                                            
     while (SIZE1<5)
     {
         int second_tests = rand() % (num_tests);    // Randomizing the linked list
         items.push(d[second_tests]->id, d[second_tests]->data);
         SIZE1++;
     }

 
    items.printList(true);  //Printing forward list 
    cout<<endl;
    items.printList(false);  //Printing backwards list 
    cout<<endl;
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.clear();
    items.printList();  //Printing list after deletion
    cout<<"The size of linked list: "<<items.findSize()<<endl;

    items.push(d[num_tests]->id, d[num_tests]->data);
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.clear(); 
    items.push(d[num_tests]->id, d[num_tests]->data);
    items.push(d[num_tests]->id, d[num_tests]->data);
    items.push(d[num_tests]->id, d[num_tests]->data);
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.clear(); 
    cout<<endl;


    //***************************************************
    //      GetNode Data test                           *
    //***************************************************
    items.push(d[num_tests]->id, d[num_tests]->data);
    DataNode *singleNode = new DataNode;

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
    items.push(d[num_tests]->id, d[num_tests]->data);
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.printList();
    items.clear(); 
    items.printList();
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    cout<<endl;


    //***************************************************
    //      Testing under random conditions             *
    //***************************************************

 
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
            cout<<"The size of linked list: "<<items.findSize()<<endl;
            break;

            case 2 :
            cout<<"Add element"<<endl;
            items.push(d[num_tests]->id, d[third_tests]->data);
            break;

            case 3 :
            cout<<"Remove element"<<endl;
            items.remove(d[third_tests]->id);
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
        cout<<endl;
        a++;  
    } //end Switch statement 

    return 0;
}

