#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
		// Constructor/Destructor
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &ref);
        ~ScavTrap();
        ScavTrap & operator=(const ScavTrap &ref);

		// Main member function
        void    guardGate();
        void    attack(const std::string& target);
        void    attack(ScavTrap& target);
        void	takeDamage(unsigned int amount);
        void	beRepaired(unsigned int amount);

        // Add on member function
		void	upDamage(int amount);
        void	print_scavTrap(std::string act1);
        void	print_scavTrap(std::string act1, std::string act2);
        void	print_scavTrap_line(std::string act1);
        void	print_scavTrap_line(std::string act1, std::string act2);
        void	print_scavTrap_line(std::string act1, std::string act2, std::string act3);
};

#endif