#include "Cat.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Cat::Cat(std::string breed) : Animal("Cat"),  _breed(breed), _sound("meow Meow") {
	print_line("Cat constructor called!");
	this->_brain = new Brain();
}

Cat::Cat() : Animal("Cat"), _breed("Not specified"), _sound("meow Meow"){
	print_line("Cat constructor called!");
	this->_brain = new Brain();
}

Cat::Cat(const Cat &ref) : Animal(ref), _breed(ref._breed), _sound(ref._sound), _brain(new Brain(*ref._brain)){
	print_line("Cat copy constructor called!");
}

Cat& Cat::operator=(const Cat &ref) {
	print_line("Cat assignment operator called!");
	if (this != &ref) {
		delete this->_brain;
		this->_type = ref._type;
		this->_breed = ref._breed;
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	print_line("Cat destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

void	Cat::makeSound() const {
	print_line(this->_sound);
}
