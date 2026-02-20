#include "DataStructures/RunDatastructures.hpp"
#include "utils/utils.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

int main()
{
    int datastructure = select_datastructure();
    int datatype = select_datatype();

    std::cout << "Enter commands in all caps to use your stack." << std::endl;
    std::cout << "If unsure with the commands, enter 'h' to see a list of available commands for your datastructure." << std::endl;

    if (datastructure == 1)
    {
        enter_stack_loop(datatype);
    }
    else if (datastructure == 2)
    {
        enter_queue_loop(datatype);
    }
    else if (datastructure == 3)
    {
        enter_map_loop(datatype);
    }
    else if (datastructure == 4)
    {
        enter_linked_list_loop(datatype);
    }
    
    return 0;
}



