#include "linkedList.h"

using namespace std;
Items::Items()
{
    head = NULL;
    count =0;

}
Items::~Items()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        // Point to the node to be deleted
        Node *garbage = ptr;
        // Go on to the next node
        ptr = ptr->next;
        // Delete the current node
        delete garbage;
    }

}
  
/*
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
*/

bool Items::push(int number, string data)  
{
    Node *nodePtr, *previousNodePtr;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->id = number;
    newNode->next = NULL;
    newNode->prev = NULL;
    cout << "pushing " << number << " " << data << endl;
    if (head == NULL)
    {
        // A new node goes at the beginning of the list
        head = newNode;
        //cout << "added empty" << endl;
    }
    else
    {
        if(head->id > number)
        {
            newNode->next = head;
            head = newNode;
            //cout << "added at start" << endl;
        }
        else if (head->id < number)
        {
            previousNodePtr = head;
            nodePtr = head->next;
            // Find the insertion point
            bool found = false;
            while (nodePtr != NULL && !found)
            {
                if(nodePtr->id < number)
                {
                previousNodePtr = nodePtr;
                nodePtr = nodePtr->next;
                }
                else if (nodePtr->id > number)
                     found = true;
                else
                    return false;
            }
            if(previousNodePtr->next != NULL)
            {
                // Insert the new node just before nodePtr
                previousNodePtr->next = newNode;
                newNode->next = nodePtr;
                newNode->prev = previousNodePtr;
                nodePtr->prev = newNode;
                //cout << "added at mid" << endl;
            }
            else
            {
                previousNodePtr->next = newNode;
                newNode->prev = previousNodePtr;
                //cout << "added at end" << endl;
            }
        }
        else
            return false;
    }
    count++;
    return true; 
} 




int Items::findSize() 
{ 
   return count; 
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
        cout << node->id << " " << node->data << endl; 
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


bool Items::remove(int number)
{
    bool success = false;
    Node *nodePtr, *previousNodePtr;
    // If the list is empty, do nothing
    if (!head)
    {
        cout<<"cant delete from empty list"<<endl;
        return success;

    } 

    
    // Determine if the first node is the one to delete
    if (head->id == number)
    {
        nodePtr = head;
        head = head->next;
        head->prev= NULL;
        delete nodePtr;
        count--;
        success= true;
    }
    else
    {
        // Initialize nodePtr to the head of the list
        nodePtr = head;
        // Skip nodes whose value member is not number
        bool match = false;
        while (nodePtr != NULL && !match)
        {
            if(nodePtr->id != number)
            {
                previousNodePtr = nodePtr;
                nodePtr = nodePtr->next;
            }
            else
                match = true;
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
            success= true;
        }
        if (!nodePtr)
        {
            cout<< number<<" is not in the list"<<endl;
            success= false;
        }
    }
    return success;
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


 bool Items::clear()
 {
     Node* currentPtr = head;
     while (head != NULL )
     {

        head = head->next;
        // Return node to the system
        currentPtr->next= NULL;
        delete currentPtr;
        currentPtr = head;
     }// end while
    count = 0;
    return true;

 }


/*
void Items::deleteLast()  
{  
    if (head == NULL) 
        return NULL; 
  
    if (head->next == NULL) { 
        delete head; 
        return NULL; 
    } 
  
    // Find the second last node 
    Node* second_last = head; 
    while (second_last->next->next != NULL) 
        second_last = second_last->next; 
  
    // Delete last node 
    delete (second_last->next); 
  
    // Change next of second last 
    second_last->next = NULL; 
  
    return head; 
	
	//return data;	
}  
*/