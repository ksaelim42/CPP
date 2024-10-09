#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main ()
{
    std::vector<int> vec;

    for (size_t i = 0; i < 6; i++)
        vec.push_back(i);
    

    if (!easyfind(vec, 10))
        std::cout << "Values: 10 not found :(" << std::endl;
    if (!easyfind(vec, 3))
        std::cout << "Values: 3 not found :(" << std::endl;
    if (!easyfind(vec, -1))
        std::cout << "Values: -1 not found :(" << std::endl;
}