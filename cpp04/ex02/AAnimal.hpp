#ifndef AANIMAL_H
# define AANIMAL_H

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal();
		AAnimal(std::string);
		AAnimal(const AAnimal &ref);
		AAnimal& operator=(const AAnimal &ref);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		// void			makeSound(AAnimal *ptr) const;
		std::string		getType() const;

};

	void	print(std::string s);
	void	print(std::string s1, std::string s2);
	void	print_line();
	void	print_line(std::string s);
	void	print_line(std::string s1, std::string s2);

#endif