/***********************************************************
Name: Tomas Vasquez 
Assignment: 03
Purpose: This program adds/deletes to head, end, and middle data structure. Additionally, it puts every number in order. It prints out forward/backwards with parameters and forward without it.
It also retrieves any node. It will not insert duplicates or print out empty lists. First set are in order while the second half are randomly generated.
Notes:  I broke this down into several functions to take away multiple if statements. 
***********************************************************/
#include "linkedList.h"

using namespace std;

//Constructor 
Items::Items()
{
    head = NULL;
    count =0;

}

//Destructor
Items::~Items()
{
    clear();
}


// Add Function
bool Items::addNode(int number, string data)  
{
    bool x;
    x= search(number);
    //cout<<"bool value: "<<x<<endl;
    if (x)
    {
        cout<<number<<" already exists"<<endl;
        return true;
    }
   

    Node *nodePtr, *previousNodePtr;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->id = number;
    newNode->forward = NULL;
    newNode->back = NULL;
    cout << "Adding: " << number << " " << data << endl;
    
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
            newNode->forward = head;
            head = newNode;
            //cout << "added at start" << endl;
        }
        else if (head->id < number)
        {
            previousNodePtr = head;
            nodePtr = head->forward;
            // Find the insertion point
            bool found = false;
            while (nodePtr != NULL && !found)
            {
                if(nodePtr->id < number)
                {
                previousNodePtr = nodePtr;
                nodePtr = nodePtr->forward;
                }
                else if (nodePtr->id > number)
                     found = true;
                else
                    return false;
            }
            if(previousNodePtr->forward != NULL)
            {
                // Insert the new node just before nodePtr
                previousNodePtr->forward = newNode;
                newNode->forward = nodePtr;
                newNode->back = previousNodePtr;
                nodePtr->back = newNode;
                //cout << "added at mid" << endl;
            }
            else
            {
                previousNodePtr->forward = newNode;
                newNode->back = previousNodePtr;
                //cout << "added at end" << endl;
            }
        }
        else
            return false;
    }
    count++;
    return true; 
} 



// Counter Function
int Items::getCount() 
{ 
   return count; 
} 


// Printing Function
void Items::printList(bool x) 
{ 
    if(head ==NULL)
    {
        cout<<"List is empty"<<endl;
        cout<<endl;
        return; 
    }


    Node* node = head;
    if (!x)
    {
        while (node->forward!= NULL)  
        {    
            node = node->forward;  
        }
    } 
    cout << endl; 
    while (node!=NULL) 
    { 
        cout << node->id << " " << node->data << endl; 
        if (x) 
        {
            node = node->forward;
        }
        else 
        {
            node = node->back;
        }
    } 
   
    
} 


// Deleting Function
bool Items::deleteNode(int number)
{
    bool success = false;
    Node *nodePtr, *previousNodePtr;
    // If the list is empty, do nothing
    if (!head)
    {
        cout<<"Cant delete from empty list!"<<endl;
        return success;

    } 

    
    // Determine if the first node is the one to delete
    if (head->id == number)
    {
        nodePtr = head;
        head = head->forward;
        head->back= NULL;
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
                nodePtr = nodePtr->forward;
            }
            else
                match = true;
        }
        // Link the previous node to the node after
        // nodePtr, then delete nodePtr
        if (nodePtr)
        {
            previousNodePtr->forward = nodePtr->forward;
            if(nodePtr->forward){
                nodePtr->forward->back=previousNodePtr;
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


// getNode Function
bool Items::getNode(int id, DataNode *node)
{
    node->id=-1;
    node->data = "";
    node->forward = NULL;
    node->back = NULL;
    cout << "Searching for node id: " << id << endl;
    if(head != NULL)
    {
        Node* current = head;
        while (current!=NULL) 
        { 
            if (id == current->id) 
            {
                //cout << "Found" << endl;
                node->id = current->id;
                node->data = current->data;
                //cout << node->id << endl;
                //cout << "assign current to node" << endl;
                return true;
            }

            current = current->forward;
        }
    }
    //cout << "Not found \n";
    return false; 
}


// Clear Function
 bool Items::clear()
 {
     Node* currentPtr = head;
     while (head != NULL )
     {
         Node* curr = head->forward;
        while (curr != NULL && curr != head)
        {
            std::cout << "Deleting: " << curr->id << std::endl;
            Node* temp = curr;
            curr = curr->forward;
            delete temp;
        };
        delete head;
        head = NULL;
        count =0;

       
     }// end while
    count = 0;
    return true;

 }

// Search Function to locate duplicate node
bool Items::search(int x)  
{  
    Node* current = head; // Initialize current  
    while (current != NULL)  
    {  
        if (current->id == x)  
            return true;  
        current = current->forward;  
    }  
    return false;  
}  