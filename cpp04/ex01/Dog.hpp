#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	std::string			_breed;
	const std::string	_sound;
	Brain				*_brain;
public:
	Dog(std::string breed);
	Dog();
	Dog(const Dog &ref);
	Dog& operator=(const Dog &ref);
	~Dog();

	void	makeSound() const;
};

#endif