#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
	print_line("=======================");
	print_line("------> ANIMALS <------");
	print_line("=======================");
	print_line();
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "[" << j->getType() << "]" << " : ";
	j->makeSound();
	std::cout << "[" << i->getType() << "]" << " : ";
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	print_line();
	print_line();
	print_line("=======================");
	print_line("---> Wrong ANIMALS <---");
	print_line("=======================");
	print_line();
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << "[" << k->getType() << "]" << " : ";
	k->makeSound(); //will not output the cat sound!
	meta2->makeSound();
	delete meta2;
	delete k;
	return 0;
}