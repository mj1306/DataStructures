#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    LLNode<T>* curr = head;
    while (curr!=nullptr)
    {
        LLNode<T>* next = curr -> next;
        delete curr;
        curr = next;
    }
}

template <typename T>
bool LinkedList<T>::push_front(const T& val)
{
    try
    {
        LLNode<T>* new_node = new LLNode<T>(val, head); // Use parametrized constructor to simplify.
        head = new_node; // Set head to be the new node we're pushing to the front.
        if (count == 0) // Make tail point to new node if empty.
        {
            tail = new_node; 
        }
    }
    catch(std::bad_alloc)
    {
        std::cerr << "Unable to perform requested operation.";
        return false;
    }
    count++;
    return true;

}

template <typename T>
bool LinkedList<T>::push_back(const T& val)
{
    try
    {
        LLNode<T>* new_node = new LLNode<T>(val, nullptr); // Use parametrized constructor to simplify.
        if (count == 0)
        {
            head = new_node; // If no values in list yet, new node is the new head.
        }
        else
        {
            tail -> next = new_node; // Set current tail's next to new_node if current tail is not a nullptr (count != 0).
        }
        tail = new_node; // Set tail to be the new node we're pushing to the back.
    }
    catch(std::bad_alloc)
    {
        std::cerr << "Unable to perform requested operation.";
        return false;
    }
    count ++;
    return true;
}

template <typename T>
T LinkedList<T>::pop_front()
{
    if (count == 0) // Check for empty list.
    {
        throw std::runtime_error("Cannot pop empty list.");
    }

    T popped_element = head -> data;

    LLNode<T>* temp = head -> next;
    delete head;
    head = temp;
    count--;
    if (count == 0)
    {
        tail = nullptr;
    }

    return popped_element;

}

template <typename T>
T LinkedList<T>::front() const
{
    if (count == 0) // Check for empty list.
    {
        throw std::runtime_error("Cannot read value from empty list.");
    }

    return head -> data;
}

template <typename T>
T LinkedList<T>::back() const
{
    if (count == 0) // Check for empty list.
    {
        throw std::runtime_error("Cannot read value from empty list.");
    }

    return tail -> data;
}

template <typename T>
bool LinkedList<T>::empty() const
{
    return count == 0;
}

template <typename T>
int LinkedList<T>::size() const
{
 return count;
}

template <typename T>
void LinkedList<T>::print_list() const
{
    if (count == 0)
    {
        throw std::runtime_error("Cannot read value from empty list.");
    }
    
    LLNode<T>* curr = head;
    while(curr != nullptr)
    {
        std::cout << curr -> data << (curr -> next != nullptr ? "->" : "\n");
        curr = curr -> next;
    }
}
