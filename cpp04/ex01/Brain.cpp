#include "Brain.hpp"

Brain::Brain() {
	print_line("Brain constructor called!");
}

Brain::Brain(const Brain &ref) {
	// print_line("Brain copy constructor called!");
	*this = ref;
}

Brain& Brain::operator=(const Brain &ref) {
	print_line("Brain assignment operator called!");
	if (this != &ref) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = ref._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	print_line("Brain destructor called!");
}