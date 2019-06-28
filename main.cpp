
#include "main.h"


int main() {

    //***************************************************
    //      Main Data test                              *
    //***************************************************
    srand(time(NULL));
    //DataNode *data[DATA_SIZE];
    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;
    Items items;
    items.clear();

    items.remove(7);        // Cant delete from head 
    items.push(7, "tom");   //Adding to head
    items.push(1, "stuff");     //Adding to head 
    items.push(4, "run");       //Adding to middle 
    items.push(6, "dog");
    items.push(8, "cat");   //Adding to tail


    items.printList(true);  //Printing list 
    items.remove(7); 
    items.printList();  //Printing list after deletion
    cout<<endl;
    items.printList(true);  //Printing list 
    cout<<endl;
    items.printList(false);  //Printing list 
    cout<<endl;
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.clear();
    items.printList();  //Printing list after deletion
    cout<<"The size of linked list: "<<items.findSize()<<endl;

    items.push(7, "tom");
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.clear(); 
    items.push(7, "tom");
    items.push(9, "animal");
    items.push(5, "pak");
    cout<<"The size of linked list: "<<items.findSize()<<endl;
    items.clear(); 


    items.push(6, "animal");
    DataNode *singleNode = new DataNode;

    if(items.getNode(6, singleNode))
    {
        cout << "main found" << endl;
    }
    else
    {
        cout << "node not found" << endl;
    }
     cout << "ID: " << singleNode->id << endl;
    cout << "Data: " << singleNode->data << endl;
    if(items.getNode(19, singleNode))
    {
        cout << "main found" << endl;
    }
    else
    {
        cout << "node not found" << endl;
    }
    cout << "ID: " << singleNode->id << endl;
    cout << "Data: " << singleNode->data << endl;

/* 
    cout<<endl;
    cout<<endl;

    //Testing for project
    cout << "Making " << num_tests << " test cases..." << endl;

    DataNode *d[num_tests];
    
    for (int i = 0; i < num_tests; i++) 
    {
        d[i] = new DataNode;
        d[i]->id = range_random(1000, 9999);
        d[i]->data = random_string(BUFFER_SIZE);
    }
    


    for (int i = 0; i < num_tests; i++) 
    {
        cout << d[i]->id << ": ";
        cout << d[i]->data << endl;
    }

    cout<<endl;
    cout<<endl;



    int a = 0;                   // Local variable counter declaration an intial condition for the loop    
    while (a<num_tests)         // while loop execution and test condition
    {
        bool x,y;
        cout<<endl;
        int selection = rand() % 12+1;
        int second_tests = rand() % (num_tests);
        cout<<"NumsS "<<second_tests<<endl;
        switch(selection) 
        {
            case 1 :
            cout<<"count"<<endl;
            cout<< "The size: "<<items.findSize();
            break;

            case 2 :
            cout<<"Add head"<<endl;
            break;

            case 3 :
            cout<<"Remove"<<endl;
            break;

            case 4:
            cout<<"Clear"<<endl;
            items.clear();
            break;

            case 5:
            cout<<"Get"<<endl;
            break;

            case 6:
            cout<<"Print"<<endl;
            items.printList();
            break;

            case 7:
            cout<<"Print"<<endl;
            items.printList(x);
            break;

            case 8:
            cout<<"Add"<<endl;
            break;

            case 9:
            cout<<"Remove"<<endl;
            break;
        }
        
        a++;  
    }
*/
    return 0;
}

