#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;
	// print_line();
	// print_line();

	// const Animal *meta[] = {new Dog(), new Dog(), new Cat(), new Cat()};
	// print_line();
	// print_line("======================");
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << meta[i]->getType() << " " << std::endl;
	// 	meta[i]->makeSound();
	// 	delete meta[i];
	// 	print_line();
	// 	print_line("======================");
	// }
	Dog	basic;
	print_line("====================");
	{
		Dog tmp = basic;
	print_line("====================");
	}
	print_line("====================");
	return 0;
}
