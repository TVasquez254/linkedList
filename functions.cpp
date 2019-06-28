#include "functions.h"

void swapData(DataNode *id1, DataNode *id2) 
{
    DataNode* temp =  id1;
    id1 = id2;
    id2 = temp;
    
}

void bubbleSortData(DataNode *d[]) 
{ 
     int i, j;
    for (i = 0; i < DATA_SIZE - 1; i++) {
        for (j = 0; j < DATA_SIZE - i - 1; j++) {
            if (d[j]->id > d[j + 1]->id) {
                swap(d[j], d[j + 1]);
            }
        }
    }
   
}

void fillData(DataNode *d[]) {
    for (int i = 0; i < DATA_SIZE; i++) {
        d[i] = new DataNode;
        d[i]->id = range_random(1000, 9999);
        d[i]->data = random_string(BUFFER_SIZE);
    }
}

void printData(DataNode *d[]) {
    for (int i = 0; i < DATA_SIZE; i++) {
        cout << d[i]->id << ": ";
        cout << d[i]->data << endl;
    }
}

string random_string(int length) {
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "01234567689";
    string randomString = "";
    char buffer[12] = "";

    int select, item;
    for (int i = 0; i < length - 2; i++) {
        select = range_random(0, 2);
        switch (select) {
            case 0:
                item = range_random(0, 25);
                buffer[i] = upper[item];
                break;
            case 1:
                item = range_random(0, 25);
                buffer[i] = lower[item];
                break;
            case 2:
                item = range_random(0, 9);
                buffer[i] = numbers[item];
                break;
        }
    }

    buffer[length - 1] = '\0';
    randomString = buffer;
    return randomString;
}

int range_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

