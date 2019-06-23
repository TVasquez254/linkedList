#include "linkedList.h"

using namespace std;
Items::Items()
{
    head = NULL;
    count =0;

}
Items::~Items()
{

}
  

bool Items::push(int new_data, string data)  
{
    struct Node* new_node = new Node;  
    new_node->id = new_data; 
    new_node->data = data;
    new_node->next = head;  
    new_node->prev = NULL;  
  
    if (head != NULL)  
        head->prev = new_node;  
  
    head = new_node; 
    count++;
    return true; 
} 




int Items::findSize() 
{ 
   return count; 
} 

/* Bubble sort the given linked list */
void Items::bubbleSort() 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
   
    /* Checking for empty list */
    if (head == NULL) 
        return; 
   
    do
    { 
        swapped = 0; 
        ptr1 = head; 
   
        while (ptr1->next != lptr) 
        { 
            if (ptr1->id > ptr1->next->id) 
            {  
                swap(ptr1->id, ptr1->next->id); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

void Items::printList(bool x) 
{ 
    if(head ==NULL)
    {
        return; 
    }


    Node* node = head;
    if (!x)
    {
        while (node->next!= NULL)  
        {    
            node = node->next;  
        }
    } 
    cout << endl; 
    while (node!=NULL) 
    { 
        cout << node->id << " "<<node->data<<endl; 
        if (x) 
        {
            node = node->next;
        }
        else 
        {
            node = node->prev;
        }
    } 
   
    
} 


void Items::remove(int number)
{
    Node *nodePtr, *previousNodePtr;
    // If the list is empty, do nothing
    if (!head) return;
    // Determine if the first node is the one to delete
    if (head->id == number)
    {
        nodePtr = head;
        head = head->next;
        head->prev= NULL;
        delete nodePtr;
        count--;
    }
    else
    {
        // Initialize nodePtr to the head of the list
        nodePtr = head;
        // Skip nodes whose value member is not number
        while (nodePtr != NULL && nodePtr->id != number)
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Link the previous node to the node after
        // nodePtr, then delete nodePtr
        if (nodePtr)
        {
            previousNodePtr->next = nodePtr->next;
            if(nodePtr->next){
                nodePtr->next->prev=previousNodePtr;
            }
            count--;
            delete nodePtr;
        }
        if (!nodePtr)
        {
            cout<< number<<" is not in the list"<<endl;
        }
    }
}


bool Items::getNode(int id, DataNode *node)
{
    if(head ==NULL)
    {
        node->id=-1;
        node->data = ""; 
        return false; 
    }


    Node* current = head;
    while (current!=NULL) 
    { 
        if (id ==node->id) 
        {
            node->id = current->id;
            node->data = current->data;
            return true;
        }

        current = current->next;
    }

    node->id=-1;
    node->data = ""; 
    return false; 
}

 
