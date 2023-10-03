#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(std::string);
		Animal(const Animal &ref);
		Animal& operator=(const Animal &ref);
		virtual ~Animal();

		virtual void	makeSound() const;
		void			makeSound(Animal *ptr) const;
		std::string		getType() const;

};

	void	print(std::string s);
	void	print(std::string s1, std::string s2);
	void	print_line();
	void	print_line(std::string s);
	void	print_line(std::string s1, std::string s2);

#endif