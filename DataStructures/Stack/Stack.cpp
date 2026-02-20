#include "Stack.hpp"

template <typename T>

Stack<T>::Stack()
{
    top = nullptr;
    size = 0;

}

template <typename T>

Stack<T>::~Stack()
{
    while (top != nullptr) // Loop through all elements and pop until nullptr is hit (stack is empty).
    {
        pop();
    }
}

template <typename T>
bool Stack<T>::push(T value)
{
    try
    {
        StackNode<T>* node = new StackNode<T>; // Create new StackNode object to store the data
        node -> data = value; // Enter data into node.
        node -> next = top; // Set the next ptr of new node as top.
        top = node; // Set top as newly stacked node.
    }
    catch(std::bad_alloc)
    {
        std::cerr << "Unable to perform requested operation.";
        return false;
    }
    
    size ++; // Size increment.
    return true;
    
    
}

template <typename T> 
T Stack<T>::peek()
{
    if (top == nullptr)
    {
        throw std::runtime_error("Cannot peek empty stack.");
    }
    return top -> data;
}

template <typename T>
bool Stack<T>::flush()
{
    if (top == nullptr)
    {
        std::cerr << "Unable to carry out flush. Stack is empty." << std::endl;
        return false;
    }

    while(top != nullptr)
    {
        std::cout << top -> data << " ";
        pop();
    }
    std::cout << std::endl;
    return true;
}

template <typename T>
T Stack<T>::pop()
{
    if (top == nullptr)
    {
        throw std::runtime_error("Cannot pop empty stack.");
    }

    StackNode<T>* temp = top -> get_next();
    T popped_element = top -> data;
    delete top;
    top = temp;
    size --;
    return popped_element;
}