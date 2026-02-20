#ifndef RUNDS_HPP
#define RUNDS_HPP

#include "Stack/Stack.hpp"
#include "Map/Map.hpp"
#include "Queue/Queue.hpp"
#include "LinkedList/LinkedList.hpp"

// Templated function that runs the while loop taking inputs from user.
template <typename T>
void run_stack(Stack<T>& stack);

template <typename T>
void run_queue();

template <typename T>
void run_map();

template <typename T>
void run_linked_list(LinkedList<T>& linked_list);

void enter_stack_loop(int datatype);

void enter_queue_loop(int datatype);

void enter_map_loop(int datatype);

void enter_linked_list_loop(int datatype);



#include "RunDatastructures.cpp"
#endif