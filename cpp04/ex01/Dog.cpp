#include "Dog.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Dog::Dog(std::string breed) : Animal("Dog"), _breed(breed), _sound("Woof woof") {
	print_line(_breed, " Dog constructor called!");
	this->_brain = new Brain();
}

Dog::Dog() : Animal("Dog"), _breed("Not specified"), _sound("Woof woof") {
	print_line(_breed, " Dog constructor called!");
	this->_brain = new Brain();
}

Dog::Dog(const Dog &ref) : Animal(ref), _breed(ref._breed), _sound(ref._sound), _brain(new Brain(*ref._brain)){
	print_line("Dog copy constructor called!");
}

Dog& Dog::operator=(const Dog &ref) {
	print_line("Dog assignment operator called!");
	if (this != &ref) {
		delete this->_brain;
		this->_type = ref._type;
		this->_breed = ref._breed;
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	print_line("Dog destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

void	Dog::makeSound() const {
	print_line(this->_sound);
}

