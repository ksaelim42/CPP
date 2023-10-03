#include "Cat.hpp"

//*********************************************************************//
//----------------------- Constuctors & Destructors -------------------//
//*********************************************************************//

Cat::Cat(std::string breed) : Animal("Cat"),  _breed(breed), _sound("meow Meow") {
	print_line("Cat constructor called!");
}

Cat::Cat() : Animal("Cat"), _breed("Not specified"), _sound("meow Meow"){
	print_line("Cat constructor called!");
}

Cat::Cat(const Cat &ref) : Animal(ref), _breed(ref._breed), _sound(ref._sound){
	print_line("Cat copy constructor called!");
}

Cat& Cat::operator=(const Cat &ref) {
	print_line("Cat assignation operator called!");
	if (this != &ref) {
		this->_type = ref._type;
		this->_breed = ref._breed;
	}
	return *this;
}

Cat::~Cat() {
	print_line("Cat destructor called!");
}


//*********************************************************************//
//----------------------- Puclic main member functions ----------------//
//*********************************************************************//

void	Cat::makeSound() const {
	print_line(this->_sound);
}
