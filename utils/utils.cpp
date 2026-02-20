#include <iostream>
#include <fstream>
#include <string>

void list_commands(const std::string& filename, const std::string& datastructure) 
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open " << filename << std::endl;
        return;
    }

    const std::string target = "[" + datastructure + "]";
    std::string line;

    // Seek to the matching section header
    while (std::getline(file, line)) {
        if (line == target) break;
    }

    // Print lines until the next section header or EOF
    while (std::getline(file, line)) {
        if (!line.empty() && line.front() == '[') break;
        std::cout << line << std::endl;
    }
}

void print_hashes(std::size_t num_hashes)
{
    for (std::size_t i{0}; i < num_hashes; i++)
    {
        std::cout << "#";
    }
    std::cout<<"\n";
}

int select_datastructure()
{
    std::size_t num_datastructures = 4;
    std::string datastructures[num_datastructures] = {"Stack", "Queue", "Map", "Linked List"};
    
    print_hashes(60);
    std::cout << "Available datastructures:" << std::endl;
    for (std::size_t i{0}; i < num_datastructures; i++)
    {
        std::cout << i+1 << ". " << datastructures[i] << std::endl;
    }
    print_hashes(60);
    std::cout << "\n";

    int datastructure;
    std::cout << "Choose a datastructure to use (Enter the number associated with the datastructure in the list below): ";

    while (std::cin >> datastructure)
    {
        if (datastructure > num_datastructures || datastructure < 1)
        {
            std::cout << "Invalid request. Please select a number from 1 to 4." << std::endl;
        }
        else
        {
            std::cout << "      -> You chose " << datastructures[datastructure-1] + "\n" << std::endl;
            break;
        }
    }
    return datastructure;
}

int select_datatype()
{
    std::size_t num_datatypes = 4;
    std::string datatypes[num_datatypes] = {"int", "double", "char", "string"};

    print_hashes(60);
    std::cout << "Available datatypes:" << std::endl;
    for (std::size_t i{0}; i < num_datatypes; i++)
    {
        std::cout << i+1 << ". " << datatypes[i] << std::endl;
    }
    print_hashes(60);
    std::cout << "\n";

    int datatype;
    std::cout << "Choose a datatype to use (Enter the number associated with the datastructure in the list below): ";

    while (std::cin >> datatype)
    {
        if (datatype > num_datatypes || datatype < 1)
        {
            std::cout << "Invalid request. Please select a number from 1 to 4." << std::endl;
        }
        else
        {
            std::cout << "      -> You chose " << datatypes[datatype-1] + "\n" << std::endl;
            break;
        }
    }

    return datatype;
}