#include "AAnimal.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

AAnimal::AAnimal(std::string type) : _type(type) {
	print_line("AAnimal constructor called!");
}

AAnimal::AAnimal() : _type("Not specified") {
	print_line("AAnimal constructor called!");
}

AAnimal::AAnimal(const AAnimal &ref) {
	this->_type = ref._type;
}

AAnimal& AAnimal::operator=(const AAnimal &ref) {
	if (this != &ref) {
		this->_type = ref._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	print_line("AAnimal destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

// void	AAnimal::makeSound() const {
// 	print_line("AAnimal sound called!");
// }


// void	AAnimal::makeSound(AAnimal *ptr) const{
// 	ptr->makeSound();
// }

std::string	AAnimal::getType() const{
	return this->_type;
}


//*********************************************************************//
//----------------------- Add on member functions ---------------------//
//*********************************************************************//

void	print_line(std::string s) {
	std::cout << s << std::endl;
}

void	print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void	print_line() {
	std::cout << std::endl;
}

void	print(std::string s) {
	std::cout << s;
}

void	print(std::string s1, std::string s2) {
	std::cout << s1 << s2;
}








