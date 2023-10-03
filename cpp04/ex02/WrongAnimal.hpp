#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include "AAnimal.hpp"

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(std::string);
	WrongAnimal(const WrongAnimal &ref);
	WrongAnimal &operator=(const WrongAnimal &ref);
	virtual ~WrongAnimal();

	void makeSound() const;
	void makeSound(WrongAnimal *ptr) const;
	std::string getType() const;
};

#endif