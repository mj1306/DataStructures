#include "RunDatastructures.hpp"
#include "../utils/utils.hpp"                                                        
#include <limits> 

/*
Main loop that takes in commands for stacks and let's user perform operations on it.
*/
template <typename T>
void run_stack(Stack<T>& stack)
{
    std::string cmd;
    std::cout << "  -> ";
    while (std::cin >> cmd)
        {
            if (cmd == "h")
            {
                list_commands("DataStructures/Commands.txt", "Stack");
            }
            else if (cmd == "PUSH")
            {
                T value;
                if (!(std::cin >> value)) // Check whether datatype entered matches the datatype chosen.
                {
                    std::cerr << "Invalid input for this datatype." << std::endl;
                    std::cin.clear(); // Clear input stream
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } 
                else
                {
                    std::cout << (stack.push(value)? "success" : "failure") << std::endl;
                }
            }

            else if (cmd == "PEEK")
            {
                std::cout << stack.peek() << std::endl;
            }

            else if (cmd == "POP")
            {
                std::cout << "Popped: " << stack.pop() << std::endl;
            }

            else if (cmd == "FLUSH")
            {
                stack.flush();
            }
            else if (cmd == "EXIT")
            {
                break;
            }
            else
            {
                std::cerr << "Invalid command. Type 'h' to see the list of available commands." << std::endl;
            }

            std::cout << "  -> ";
        }
}

template <typename T>
void run_queue()
{
    std::string cmd;
    std::cout << "  -> ";
    while (std::cin >> cmd)
        {
            if (cmd == "h")
            {
                list_commands("DataStructures/Commands.txt", "Queue");
            }
            else if (cmd == "EXIT")
            {
                break;
            }
            else
            {
                std::cerr << "Invalid command. Type 'h' to see the list of available commands." << std::endl;
            }
        }
}

template <typename T>
void run_map()
{
    std::string cmd;
    std::cout << "  -> ";
    while (std::cin >> cmd)
        {
            if (cmd == "h")
            {
                list_commands("DataStructures/Commands.txt", "Map");
            }
            else if (cmd == "EXIT")
            {
                break;
            }
            else
            {
                std::cerr << "Invalid command. Type 'h' to see the list of available commands." << std::endl;
            }
        }
}

template <typename T>
void run_linked_list(LinkedList<T>& linked_list)
{
    std::string cmd;
    std::cout << "  -> ";
    while (std::cin >> cmd)
        {
            if (cmd == "h")
            {
                list_commands("DataStructures/Commands.txt", "Linked List");
            }
            else if (cmd == "PUSH_FRONT")
            {
                T value;
                if (!(std::cin >> value)) // Check whether datatype entered matches the datatype chosen.
                {
                    std::cerr << "Invalid input for this datatype." << std::endl;
                    std::cin.clear(); // Clear input stream
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }     
                else
                {
                    std::cout << (linked_list.push_front(value)? "success" : "failure") << std::endl;
                }
            }
            else if (cmd == "PUSH_BACK")
            {
                T value;
                if (!(std::cin >> value)) // Check whether datatype entered matches the datatype chosen.
                {
                    std::cerr << "Invalid input for this datatype." << std::endl;
                    std::cin.clear(); // Clear input stream
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } 
                else
                {
                    std::cout << (linked_list.push_back(value)? "success" : "failure") << std::endl;
                }
            }
            else if (cmd == "POP_FRONT")
            {
                std::cout << "Popped: " << linked_list.pop_front() << std::endl;
            }
            else if (cmd == "FRONT")
            {
                std::cout << "Front is: " << linked_list.front() << std::endl;
            }
            else if (cmd == "BACK")
            {
                std::cout << "Back is: " << linked_list.back() << std::endl;
            }
            else if (cmd == "EMPTY")
            {
                std::cout << "List is " << (linked_list.empty()? "empty." : "not empty.") << std::endl;
            }
            else if (cmd == "SIZE")
            {
                std::cout << "Size is " << linked_list.size() << std::endl;
            }
            else if (cmd == "PRINT")
            {
                linked_list.print_list();
            }
            else if (cmd == "EXIT")
            {
                break;
            }
            else
            {
                std::cerr << "Invalid command. Type 'h' to see the list of available commands." << std::endl;
            }
            std::cout << "  -> ";
        }
}

void enter_stack_loop(int datatype)
{
    if (datatype == 1)
        {
            Stack<int> stack;
            run_stack(stack);
        }
        else if (datatype == 2)
        {
            Stack<double> stack;
            run_stack(stack);
        }
        else if (datatype == 3)
        {
            Stack<char> stack;
            run_stack(stack);
        }
        else if (datatype == 4)
        {
            Stack<std::string> stack;
            run_stack(stack);
        }
}

void enter_queue_loop(int datatype)
{

}

void enter_map_loop(int datatype)
{

}

void enter_linked_list_loop(int datatype)
{
    if (datatype == 1)
    {
        LinkedList<int> linked_list;
        run_linked_list(linked_list);
    }
    else if (datatype == 2)
    {
        LinkedList<double> linked_list;
        run_linked_list(linked_list);
    }
    else if (datatype == 3)
    {
        LinkedList<char> linked_list;
        run_linked_list(linked_list);
    }
    else if (datatype == 4)
    {
        LinkedList<std::string> linked_list;
        run_linked_list(linked_list);
    }
}