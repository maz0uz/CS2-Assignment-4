



// Mohamed Azouz
// 900225230

#include "LinkedLists.hpp"


LinkedLists :: LinkedLists() // Linked Lists constructor sets the attributes to reflect an empty linked list
{
    head = NULL;
    temp = head;
}
void LinkedLists :: add(int n) // Add function accepts a number to add to the linked list
{
    if(head == NULL) // Checks if the linked list is empty, if it is it will change the head (first element) to reflect the new number
    {
        head = new Node;
        head->num = n;
        head->occurences = 1;
        head->next = NULL;
        temp = head;
    }
    else
    {
        Node *t = head;
        bool x = false;
        while(t != NULL)
        {
            if(t->num == n) // Checks if the number is already present in the linked list
            {
                t->occurences++; // If the number exists, it increments its occurences in stead of adding a new element
                x = true;
            }
            t = t->next;
        }
        if(!x) // If the number is not found, it adds a new node to the linked list and sets its occurences to 1
        {
            temp->next = new Node;
            temp = temp->next;
            temp->num = n;
            temp->occurences=1;
            temp->next = NULL;
        }
        x = false;
        t = head;
    }
}
void LinkedLists :: remove(int index) // remove function searches for a number to remove by the index in the linked list
{
    Node *t1 = head;
    if(index == 0)
    {
        head = head-> next;
        delete t1;
    }else
    {
        for(int i=0; i<index-1; i++)
        {
            t1 = t1->next;
        }
        Node * t2 = t1->next;
        t1->next = t2->next;
        delete t2;
        if(t1->next == NULL)
            temp = t1;
    }
}
void LinkedLists :: print() // Print function displays all the nodes in the linked list. If a node has multiple occurences, the number is printed as many times as the occurences.
{
    Node * t = head;
    cout<<"Numbers in linked list (appearing as many times as their occurences):"<<endl;
    while(t != NULL)
    {
        for(int i=0;i<t->occurences;i++)
            cout<<t->num<<" ";
        t = t->next;
    }
}
void LinkedLists :: constructFromVector(vector<int> v) // Construct from vector function adds all the elements in a vector (of type int) to the linked list using the add function
{
    vector<int>::iterator p;
    for(p=v.begin();p<v.end();p++)
    {
        add(*p);
    }
}
int LinkedLists :: sum() // sum function sums up all the nodes of the linked list
{
    int s=0;
    Node *t = head;
    while(t != NULL)
    {
        s += t->num*t->occurences; // makes sure to add the number multiplied by its occurences.
        t = t->next;
    }
    return s;
}

LinkedLists :: ~LinkedLists() // Destructor deletes all pointers.
{
    Node *t;
    while(head != temp)
    {
        t = head;
        head = head->next;
        delete t;
    }
    delete head;
}
