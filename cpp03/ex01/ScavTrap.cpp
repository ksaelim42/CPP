#include "ScavTrap.hpp"


//**************************************************//
//-------------- Constructor/Destructor ------------//
//**************************************************//

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    print_scavTrap_line("is coming");
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    print_line("  Name : ", this->_name);
    print_line("    HP : ", ft_itos(this->_hitPoint));
    print_line("    EP : ", ft_itos(this->_energyPoint));
    print_line("Damage : ", ft_itos(this->_attackDamage));
    print_line();
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

void ScavTrap::attack(const std::string& target) {
    if (!checkPoint())
        return;
    this->_energyPoint -= 1;
    print_scavTrap("attack");
    print(" ");
    print_line(target, " to lose ", ft_itos(this->_attackDamage), " hitpoit T^T");
}

void ScavTrap::takeDamage(unsigned int amount) {
    print_scavTrap_line("take", ft_itos(amount), "damage ToT");
    this->_hitPoint -= amount;
    if (this->_hitPoint <= 0)
        print_scavTrap_line("is Died x_x");
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (!checkPoint())
        return;
    this->_energyPoint -= 1;
    this->_hitPoint += amount;
    print_scavTrap_line("get", ft_itos(amount), "hitPoint ^_^");
}

//**************************************************//
//---------- Public Add on member function ---------//
//**************************************************//

void ScavTrap::upDamage(int amount) {
    this->_attackDamage += amount;
    print_scavTrap_line("power up", ft_itos(amount), "attack damage ^^");
}

void ScavTrap::attack(ScavTrap &target) {
    attack(target.getname());
    target.takeDamage(this->getDamage());
}

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