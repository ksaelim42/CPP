#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data *test = new Data();

    test->name = "Me";

    uintptr_t serializedData =  Serializer::serialize(test);
    
    std::cout << serializedData <<std::endl;

    Data *test2 = Serializer::deserialize(serializedData);

    std::cout << test2->name << std::endl;

    delete test;
}