#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		// Constructor/Destructor
        FragTrap(std::string name);
        FragTrap(const FragTrap &ref);
        ~FragTrap();
        FragTrap & operator=(const FragTrap &ref);

		// Main member function
        void    highFivesGuys(void);
        void	attack(const std::string& target);
        void	attack(FragTrap &target);
        void	takeDamage(unsigned int amount);
        void	beRepaired(unsigned int amount);

        // Add on member function
		void	upDamage(int amount);
        void	print_fragTrap(std::string act1);
        void	print_fragTrap(std::string act1, std::string act2);
        void	print_fragTrap_line(std::string act1);
        void	print_fragTrap_line(std::string act1, std::string act2);
        void	print_fragTrap_line(std::string act1, std::string act2, std::string act3);
};

#endif