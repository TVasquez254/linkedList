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
bool Items::push(int number, string data)  
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
    newNode->next = NULL;
    newNode->prev = NULL;
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



// Counter Function
int Items::findSize() 
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


// Deleting Function
bool Items::remove(int number)
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


// getNode Function
bool Items::getNode(int id, DataNode *node)
{
    node->id=-1;
    node->data = "";
    node->next = NULL;
    node->prev = NULL;
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

            current = current->next;
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
         Node* curr = head->next;
        while (curr != NULL && curr != head)
        {
            std::cout << "Deleting: " << curr->id << std::endl;
            Node* temp = curr;
            curr = curr->next;
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
        current = current->next;  
    }  
    return false;  
}  