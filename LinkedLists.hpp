



// Mohamed Azouz
// 900225230

#ifndef LinkedLists_hpp
#define LinkedLists_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#endif /* LinkedLists_hpp */

using namespace std;

class LinkedLists
{
private:
    struct Node // Node struct is used to create each node in the linked list
    {
        int num; // the data of each node is stored in the num and occurences variables
        int occurences;
        Node * next; // a node is created to represent the next node in the linked list
    };
    Node * head; // head pointer node represents the first node in the linked list
    Node * temp; // temp node is used to point at the last node in the linked list.
public:
    LinkedLists();
    void add(int n);
    void remove(int index);
    void print();
    void constructFromVector(vector<int> v);
    int sum();
    ~LinkedLists();
};
