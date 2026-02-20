#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include "../../Node/StackNode.hpp"

template <typename T>

class Stack
{
    private:
        int size;
        StackNode<T>* top; // Pointer to top of stack
    public:
        /*
        Constructors and destructor 
        */

        Stack(); // top = nullptr; size = 0;
        ~Stack(); // Sequentially remove all elements of stack top to bottom

        /*
        Methods
        */

        bool push(T value); // Push a value onto the stack
        T peek(); // Return the value of top element
        T pop(); // Return true if succesfully popped top element, else false.
        bool flush(); // Remove all elements top to bottom and print each element as it gets removed. Return true if success, else false.

};

#include "Stack.cpp"
#endif
