#include "Dog.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Dog::Dog(std::string breed) : Animal("Dog"), _breed(breed), _sound("Woof woof") {
	print_line("Dog [", _breed, "] constructor called!");
}

Dog::Dog() : Animal("Dog"), _breed("Not specified"), _sound("Woof woof") {
	print_line("Dog [", _breed, "] constructor called!");
}

Dog::Dog(const Dog &ref) : Animal(ref), _breed(ref._breed), _sound(ref._sound) {
	print_line("Dog copy constructor called!");
}

Dog& Dog::operator=(const Dog &ref) {
	print_line("Dog assignation operator called!");
	if (this != &ref) {
		this->_type = ref._type;
		this->_breed = ref._breed;
	}
	return *this;
}

Dog::~Dog() {
	print_line("Dog destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

void	Dog::makeSound() const {
	print_line(this->_sound);
}
