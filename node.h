#ifndef NODE
#define NODE
#include <iostream>
using namespace std;

template <class T>
struct Node{


    T item;
    Node* next;
    Node* previous;

    //Constructor
    //================================

    //Initialize item with _item
    Node(T _item):item(_item),next(NULL),previous(NULL){}

    //Default Constructor
    //=================================
    Node():item(T()),next(NULL),previous(NULL){}

    template <class U>
    friend ostream& operator<<(ostream& outs,const Node<U> RHS);
    //Precondition: RHS node can be any type
    //Postcondition: return the node

};


template <class U>

ostream& operator<<(ostream& outs,const Node<U> RHS){

    outs<<RHS.item;

    return outs;
}

#endif // NODE

