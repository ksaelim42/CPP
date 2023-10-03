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
		
        // Add on member function
        void	print_scavTrap(std::string act1);
        void	print_scavTrap(std::string act1, std::string act2);
        void	print_scavTrap_line(std::string act1);
        void	print_scavTrap_line(std::string act1, std::string act2);
        void	print_scavTrap_line(std::string act1, std::string act2, std::string act3);
};

#endif