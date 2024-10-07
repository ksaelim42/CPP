#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 100

int main()
{
	Array<int> myArray(MAX_VAL);
	int* intPointer = new int[MAX_VAL];
	srand(time(NULL));


    std::cout << "myArray Size: " << myArray.size() << std::endl;

	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		myArray[i] = value;
		intPointer[i] = value;
	}

    std::cout << "myArray Values    : " << myArray[MAX_VAL - 1] << std::endl;
    std::cout << "intPointer Values : " << intPointer[MAX_VAL - 1] << std::endl;

	{
		Array<int> tmp = myArray;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (intPointer[i] != myArray[i]) {
			std::cerr << "not same value!!" << std::endl;
			return 1;
		}
	}

	try {
		myArray[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		myArray[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
		myArray[i] = rand();
	
    delete [] intPointer;

	return 0;
}
