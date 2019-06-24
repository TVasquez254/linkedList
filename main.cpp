
#include "main.h"


int main() {
    srand(time(NULL));

    DataNode *data[DATA_SIZE];

    fillData(data);
    printData(data);
    cout << endl;
    bubbleSortData(data);
    printData(data);
    cout << endl;
    cout << endl;

    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;
    Items items;
    
    items.push(7, "tom"); 
    items.push(1, "stuff");  
    items.push(4, "run"); 
    items.push(6, "dog");
    items.push(8, "cat"); 
    items.bubbleSort(); 
    items.printList(true);
    cout<< "the size: "<<items.findSize();
    items.remove(4);
    items.printList(true);
    cout<<endl;
    cout<< "the size: "<<items.findSize();
    cout<<endl;

   
    items.clear();
    cout<<endl;
    items.printList(true);
    cout<< "the size: "<<items.findSize();
    cout<<endl;
    cout << "Making " << num_tests << " test cases..." << endl;
    int a = 0;                   // Local variable counter declaration an intial condition for the loop    
    while (a<num_tests)         // while loop execution and test condition
    {
        cout<<endl;
        int selection = rand() % 6 + 1;
        switch(selection) 
        {
            case 1 :
            cout<<"count"<<endl;
            break;

            case 2 :
            cout<<"add"<<endl;
            break;

            case 3 :
            cout<<"remove"<<endl;
            break;

            case 4:
            cout<<"clear"<<endl;
            break;

            case 5:
            cout<<"get"<<endl;
            break;

            case 6:
            cout<<"print"<<endl;
            break;
        }
        
        a++;  
    }







/*
        //pushing all the test cases to the stack
    cout << "Testing pushing all test cases to stack" << endl;
    for (int i = 0; i < num_tests; i++) {
        if (stack.push(ids[i], data[i])) {
            cout << "\t" << i + 1 << ") " << ids[i] << ": " << data[i] << " pushed to stack." << endl;
        } else {
            if (stack.count() == STACK_SIZE) {
                cout << "\tstack is full" << endl;
            } else {
                cout << "\terror: something went wrong" << endl;
            }
        }
    }
    cout << "Testing pushing all test cases done" << endl << endl;
*/
    return 0;
}

