#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data *test = new Data();

    test->name = "Hello";

    uintptr_t serializedData =  Serializer::serialize(test);
    
    std::cout << serializedData <<std::endl;

    Data *test1 = Serializer::deserialize(serializedData);

    std::cout << test1->name << std::endl;

    delete test;
}