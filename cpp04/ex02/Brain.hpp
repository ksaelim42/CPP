#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "AAnimal.hpp"

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain &ref);
	Brain& operator=(const Brain &ref);
	~Brain();
};

#endif