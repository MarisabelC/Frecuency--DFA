#ifndef STACK
#define STACK
#include "linklist.h"

template <class T>
class Stack{

public:
    Stack();

    //Big Three

    //Copy Constructor
    Stack(const Stack<T>& s);

    //Destructor
    ~Stack();

    //Assigment Operator

    Stack& operator =(const Stack& list);

    void push(T item);
    //Precondition: item can be any type.
    //Postcondition: Inserts a new element at the top of the stack,
    //above its current top element.

    T pop();
    //Precondition:The stack needs to have an element

    //Postcondition:Removes the element on top of the stack,
    //effectively reducing its size by one.
    //The element removed is the latest element
    //inserted into the stack.Return the elements on top of the stack

    T &top();
    //Precondition:The stack needs to have an element
    //Postcondition:Since stacks are last-in first-out containers,the top element is the
    //last element inserted into the stac


    bool empty();
    //Precondition: container contains 0 or more elements
    //postcondition:Returns whether the stack is empty


    int size()const;
    //Return the numbers of elements in the stack

    template <class U>
    friend ostream& operator<<(ostream& outs,const Stack<U>& RHS);

    private:


    Node<T>* _stack;
    int _size;

};

#endif // Stack

template<class T>
Stack<T>::Stack():_stack(NULL),_size(0){}

//Big Three
//Copy constructor
template<class T>
Stack<T>::Stack(const Stack<T> &s){
    _stack=NULL;
    _CopyList(s._stack,_stack);
    _size=s.size();

}

//Destructor
template<class T>
Stack<T>::~Stack(){

    _ClearAll(_stack);
}

//Assigment Operator
template<class T>
Stack<T>&Stack<T>::operator=(const Stack<T>& list){

    if (this!=&list){

        _ClearAll(_stack);
        _stack=NULL;
        _CopyList(list._stack,_stack);
        _size=getSize(list._stack());
}

    return *this;

}

template<class T>
void Stack<T>::push(T item){

    _InsertHead(_stack,item);
    _size++;

}

template<class T>
T Stack<T>::pop(){

    if(!empty()){
        _size--;
        return _RemoveHead(_stack);
    }

    throw 0;
}


template<class T>
T &Stack<T>::top(){

    if (!empty())
        return _stack->item;
    throw 0;
}

template<class T>
bool Stack<T>::empty(){

    if (_size==0)
        return true;
    if (_size>0)
        return false;
    throw 0;

}

template<class T>
int Stack<T>::size()const{

    if (_size>=0)
        return _size;
    throw 0;
}

template <class U>
ostream& operator<<(ostream& outs,const Stack<U>& RHS){

    outs<<RHS._stack;
    return outs;
}



