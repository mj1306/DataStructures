#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "../../Node/LLNode.hpp"
#include <iostream>

template <typename T>
class LinkedList
{
    private:
        LLNode<T>* head;
        LLNode<T>* tail;
        int count;

    public:

        LinkedList();
        ~LinkedList();
        bool push_front(const T& val);
        bool push_back(const T& val);
        T pop_front();
        T front() const;
        T back() const;
        bool empty() const;
        int size() const;
        void print_list() const;

};

#include "LinkedList.cpp"
#endif
