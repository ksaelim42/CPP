#include "ScavTrap.hpp"


//**************************************************//
//-------------- Constructor/Destructor ------------//
//**************************************************//

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref) {
    print("Copy of");
    print(" ");
    print_scavTrap_line("is coming");
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref) {
    print("Copy of");
    print(" ");
    print_scavTrap_line("is coming", "** with assignment operator(=) **");
    if (this != &ref) {
        this->_name = ref._name;
        this->_hitPoint = ref._hitPoint;
        this->_energyPoint = ref._energyPoint;
        this->_attackDamage = ref._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    print_line();
    print_scavTrap_line("waving hand... :)");
}


//**************************************************//
//----------- Public Main member function ----------//
//**************************************************//

void ScavTrap::guardGate() {
    print_scavTrap_line("is now in Gate keeper mode.");
}


//**************************************************//
//---------- Public Add on member function ---------//
//**************************************************//

void ScavTrap::print_scavTrap(std::string act) {
    print("ScavTrap ", this->_name, " ", act);
}

void ScavTrap::print_scavTrap(std::string act1, std::string act2) {
    print("ScavTrap ", this->_name);
    print(" ", act1, " ", act2);
}

void ScavTrap::print_scavTrap_line(std::string act) {
    print_line("ScavTrap ", this->_name, " ", act);
}

void ScavTrap::print_scavTrap_line(std::string act1, std::string act2) {
    print("ScavTrap ", this->_name);
    print_line(" ", act1, " ", act2);
}

void ScavTrap::print_scavTrap_line(std::string act1, std::string act2, std::string act3) {
    print("ScavTrap ", this->_name, " ", act1);
    print_line(" ", act2, " ", act3);
}