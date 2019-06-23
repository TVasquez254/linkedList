
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


    cout << "Testing adding all nodes to list" << endl;
    for (int i = 0; i < num_tests; i++) {
        if (items.push(id[i], data[i])) {
            cout << "\t" << i + 1 << ") " << id[i] << ": " << data[i] << " added to list." << endl;
        } else {
                cout << "\t error: something went wrong" << endl;
            }
        }

/*
    //delete the test cases from the stack
    cout << "Testing deleting all nodes from list" << endl;
    for (int i = 0; i < num_tests; i++) {
        if (items.delete(&tempData)) {
            cout << "\t" << tempData.id << ": " << tempData.data << " deleted from list." << endl;
        } else {
            if (items.count() == 0) {
                cout << "\t list is empty" << endl;
            } else {
                cout << "\terror: something went wrong" << endl;
            }
        }
    }
    cout << "Testing deleting all test cases done" << endl << endl;

*/
    return 0;
}

