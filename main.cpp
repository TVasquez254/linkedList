
#include "main.h"


int main() {
    srand(time(NULL));

    DataNode *data[DATA_SIZE];

    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;


    
    Items items;
    
    bool x;
    items.clear();

 
    items.push(7, "tom"); 
    items.push(1, "stuff"); 
    items.push(4, "run"); 
    items.push(6, "dog");
    items.push(8, "cat"); 
    /*
  

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



*/

    items.printList(true);
    items.printList(false);
    cout<< "the size: "<<items.findSize();
    cout<<endl;
    cout<<"Bool of remove: "<<items.remove(4);
    cout<<endl;
    items.printList(true);
    cout<<endl;
    cout<< "the size: "<<items.findSize();
    cout<<endl;
    cout<<"Bool of clear: "<<items.clear();
    cout<<endl;
    items.printList(true);
    cout<< "the size: "<<items.findSize();
    cout<<endl;
    //x=items.remove(2);
    //cout<<"Bool of remove: "<<x<<endl;

/*
    DataNode *d[num_tests];
    DataNode *e[num_tests];
    
    for (int i = 0; i < num_tests; i++) 
    {
        d[i] = new DataNode;
        d[i]->id = range_random(1000, 9999);
        d[i]->data = random_string(BUFFER_SIZE);
    }
    

    for (int i = 0; i < num_tests; i++) 
    {
        e[i] = new DataNode;
        e[i]->id = range_random(1000, 9999);
        e[i]->data = random_string(BUFFER_SIZE);
    }


    for (int i = 0; i < num_tests; i++) 
    {
        cout << d[i]->id << ": ";
        cout << d[i]->data << endl;
    }

    cout<<endl;
    cout<<endl;

    for (int i = 0; i < num_tests; i++) 
    {
        cout << e[i]->id << ": ";
        cout << e[i]->data << endl;
    }

        cout<<endl;
        cout<<endl;



    //Testing for project
    cout << "Making " << num_tests << " test cases..." << endl;

    DataNode *d[num_tests];
    DataNode *e[num_tests];
    
    for (int i = 0; i < num_tests; i++) 
    {
        d[i] = new DataNode;
        d[i]->id = range_random(1000, 9999);
        d[i]->data = random_string(BUFFER_SIZE);
    }
    

    for (int i = 0; i < num_tests; i++) 
    {
        e[i] = new DataNode;
        e[i]->id = range_random(1000, 9999);
        e[i]->data = random_string(BUFFER_SIZE);
    }


    for (int i = 0; i < num_tests; i++) 
    {
        cout << d[i]->id << ": ";
        cout << d[i]->data << endl;
    }

    cout<<endl;
    cout<<endl;

    for (int i = 0; i < num_tests; i++) 
    {
        cout << e[i]->id << ": ";
        cout << e[i]->data << endl;
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
                for (int i = 0; i < num_tests; i++) 
                {
                    if (d[i]->id==e[second_tests]->id)
                    {
                        x= items.push(e[second_tests]->id, e[second_tests]->data);
                        cout << "Item: "<<e[second_tests]->id << ": "<< e[second_tests]->data << " was added."<<endl;
                    }
                }
            break;

            case 3 :
            cout<<"Remove"<<endl;
            
            for (int i = 0; i < num_tests; i++) 
                {
                    if (d[i]->id==e[second_tests]->id)
                    {
                        y= items.remove(e[second_tests]->id);
                        cout << "Item: "<<e[second_tests]->id << ": "<< e[second_tests]->data << " was deleted."<<endl;
                    }
                }
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
            cout<<"Delete Tail"<<endl;
            break;

            case 8:
            cout<<"Delete Head"<<endl;
            break;

            case 9:
            cout<<"Delete Middle"<<endl;
            break;

            case 10:
            cout<<"Print"<<endl;
            items.printList(x);
            break;

            case 11:
            cout<<"Add"<<endl;
            items.push(e[second_tests]->id, e[second_tests]->data);
            break;

            case 12:
            cout<<"Remove"<<endl;
            items.remove(e[second_tests]->id);
            break;
        }
        
        a++;  
    }
*/
    return 0;
}

