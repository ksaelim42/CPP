#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>
#include <sstream>

class ClapTrap
{
    protected:
        std::string		_name;
        int				_hitPoint;
        int				_energyPoint;
        int				_attackDamage;
    public:

		// Constructor/Destructor
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ref);
        ~ClapTrap();
        ClapTrap & operator=(const ClapTrap &ref);

		// Main member function
        void	attack(const std::string& target);
        void	attack(ClapTrap &target);
        void	takeDamage(unsigned int amount);
        void	beRepaired(unsigned int amount);

		// Add on member function
		std::string		getname();
		int				getDamage();
		int				getHP();
		int				getEP();
        bool			checkPoint(void);

		void	upDamage(int amount);
        void	print_clapTrap(std::string act1);
        void	print_clapTrap(std::string act1, std::string act2);
        void	print_clapTrap_line(std::string act1);
        void	print_clapTrap_line(std::string act1, std::string act2);
        void	print_clapTrap_line(std::string act1, std::string act2, std::string act3);
};

// Add on function
std::string     ft_itos(int i);

void			print(std::string s);
void			print(std::string s1, std::string s2);
void			print(std::string s1, std::string s2, std::string s3);
void			print(std::string s1, std::string s2, std::string s3, std::string s4);
void			print_line(std::string s);
void			print_line(std::string s1, std::string s2);
void			print_line(std::string s1, std::string s2, std::string s3);
void			print_line(std::string s1, std::string s2, std::string s3, std::string s4);
void			print_line(void);
void			print_intro(std::string name1, std::string name2);
void			print_end(std::string name);

#endif