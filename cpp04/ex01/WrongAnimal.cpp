#include "WrongAnimal.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	print_line("WrongAnimal constructor called!");
}

WrongAnimal::WrongAnimal() : _type("Not specified") {
	print_line("WrongAnimal constructor called!");
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) {
	this->_type = ref._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref) {
	if (this != &ref) {
		this->_type = ref._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	print_line("WrongAnimal destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

void	WrongAnimal::makeSound() const {
	print_line("WrongAnimal sound called!");
}


void	WrongAnimal::makeSound(WrongAnimal *ptr) const {
	ptr->makeSound();
}

std::string	WrongAnimal::getType() const{
	return this->_type;
}


//*********************************************************************//
//----------------------- Puclic Add on member functions --------------//
//*********************************************************************//

//write your code here


//*********************************************************************//
//----------------------- Add on member functions ---------------------//
//*********************************************************************//

