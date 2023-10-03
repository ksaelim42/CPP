#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	std::string			_breed;
	const std::string	_sound;
public:
	WrongCat(std::string breed);
	WrongCat();
	WrongCat(const WrongCat &ref);
	WrongCat& operator=(const WrongCat &ref);
	~WrongCat();

	void	makeSound() const;
};

#endif