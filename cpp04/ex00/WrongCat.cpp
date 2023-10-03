#include "WrongCat.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

WrongCat::WrongCat(std::string breed) : WrongAnimal("WrongCat"),  _breed(breed), _sound("meow Meow") {
	print_line("WrongCat constructor called!");
}

WrongCat::WrongCat() : WrongAnimal("WrongCat"), _breed("Not specified"), _sound("meow Meow"){
	print_line("WrongCat constructor called!");
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal(ref), _breed(ref._breed), _sound(ref._sound) {
	print_line("WrongCat copy constructor called!");
}

WrongCat& WrongCat::operator=(const WrongCat &ref) {
	print_line("WrongCat assignation operator called!");
	if (this != &ref) {
		this->_type = ref._type;
		this->_breed = ref._breed;
	}
	return *this;
}

WrongCat::~WrongCat() {
	print_line("WrongCat destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

void	WrongCat::makeSound() const {
	print_line(this->_sound);
}
