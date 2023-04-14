



// Mohamed Azouz
// 900225230

#include <iostream>
#include <vector>
#include <iterator>
#include "LinkedLists.hpp"
using namespace std;


void insertAfter(int firstValue, int secondValue, vector<int> &num) // insertAfter function searches for the firstvalue in the vector and when it is found it inserts the second value next to it whenever found
{
    vector<int>::iterator p; // an iterator is used to go through the elements in the vectors
    for(p=num.begin();p<num.end();p++)
    {
        if(*p==firstValue)
        {
            p=num.insert(p+1,secondValue);
            p++; // the iterator must be incremented within the function so that if the firstValue and secondValue are equal, it does not create an infinite loop as it keeps revisiting the value it just inserted.
        }
    }
}

int main()
{
    vector<int> num;
    int n;
    
    cout<<"How many numbers would you like to enter? ";
    cin >> n;
    int x;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number: ";
        cin>>x;
        num.push_back(x);
    }
    
    cout<<"Vector before inserAfter function:"<<endl;
    vector<int>::iterator p;
    for(p=num.begin();p<num.end();p++)
    {
        cout<<*p<<" ";
    }
    cout<<endl;
    cout<<"Insert first value: ";
    cin>>x;
    cout<<"Insert second value: ";
    int y;
    cin>>y;
    insertAfter(x,y,num);
    cout<<"Vector after insertAfter function:"<<endl;
    for(p=num.begin();p<num.end();p++)
    {
        cout<<*p<<" ";
    }cout<<endl;
    
    cout<<"Now Constructing Linked List from Vector"<<endl;
    LinkedLists LL;
    LL.constructFromVector(num);
    LL.print();cout<<endl;
    cout<<"Linked List Sum (Taking into account the occurences): "<<LL.sum()<<endl;
}
