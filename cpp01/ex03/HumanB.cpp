#include "HumanB.hpp"

void HumanB::attack(void)
{
	if (this->_weapon != NULL && !this->_weapon->getType().empty())
		print_line(this->_name, " attacks with their ", this->_weapon->getType());
	else
		print_line(this->_name, " has no weapon");
	// std::cout << "123q34q34q34" << std::endl;
	// if (this->_weapon != NULL)
	// 	print_line(this->_name, "attacks with their ", this->_weapon->getType());
	// else
	// 	print_line(this->_name, "here");
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) : _weapon(NULL)
{
	this->_name = name;
}

HumanB::~HumanB() {}
