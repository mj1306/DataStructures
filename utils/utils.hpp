#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

void list_commands(const std::string& filename, const std::string& datastructure);
void print_hashes(std::size_t num_hashes);

int select_datastructure();
int select_datatype();

#endif 