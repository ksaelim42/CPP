#include "FragTrap.hpp"


//**************************************************//
//-------------- Constructor/Destructor ------------//
//**************************************************//

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    print_line("  Name : ", this->_name);
    print_line("    HP : ", ft_itos(this->_hitPoint));
    print_line("    EP : ", ft_itos(this->_energyPoint));
    print_line("Damage : ", ft_itos(this->_attackDamage));
    print_line();
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref) {
    print("Copy of");
    print(" ");
    print_fragTrap_line("is coming");
}

FragTrap& FragTrap::operator=(const FragTrap &ref) {
    print("Copy of");
    print(" ");
    print_fragTrap_line("is coming", "** with assignment operator(=) **");
    if (this != &ref) {
        this->_name = ref._name;
        this->_hitPoint = ref._hitPoint;
        this->_energyPoint = ref._energyPoint;
        this->_attackDamage = ref._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap(){
    print_line();
    highFivesGuys();
}


//**************************************************//
//----------- Public Main member function ----------//
//**************************************************//

void FragTrap::highFivesGuys(void) {
    print_fragTrap_line("is going to high five now");
}

void FragTrap::attack(const std::string& target) {
    if (!checkPoint())
        return;
    this->_energyPoint -= 1;
    print_fragTrap("attack");
    print(" ");
    print_line(target, " to lose ", ft_itos(this->_attackDamage), " hitpoit T^T");
}

void FragTrap::takeDamage(unsigned int amount) {
    print_clapTrap_line("take", ft_itos(amount), "damage ToT");
    this->_hitPoint -= amount;
    if (this->_hitPoint <= 0)
        print_fragTrap_line("is Died x_x");
}

void FragTrap::beRepaired(unsigned int amount) {
    if (!checkPoint())
        return;
    this->_energyPoint -= 1;
    this->_hitPoint += amount;
    print_fragTrap_line("get", ft_itos(amount), "hitPoint ^_^");
}

//**************************************************//
//---------- Public Add on member function ---------//
//**************************************************//

void FragTrap::upDamage(int amount) {
    this->_attackDamage += amount;
    print_fragTrap_line("power up", ft_itos(amount), "attack damage ^^");
}

void FragTrap::attack(FragTrap &target) {
    attack(target.getname());
    target.takeDamage(this->getDamage());
}

void FragTrap::print_fragTrap(std::string act) {
    print("FragTrap ", this->_name, " ", act);
}

void FragTrap::print_fragTrap(std::string act1, std::string act2) {
    print("FragTrap ", this->_name);
    print(" ", act1, " ", act2);
}

void FragTrap::print_fragTrap_line(std::string act) {
    print_line("FragTrap ", this->_name, " ", act);
}

void FragTrap::print_fragTrap_line(std::string act1, std::string act2) {
    print("FragTrap ", this->_name);
    print_line(" ", act1, " ", act2);
}

void FragTrap::print_fragTrap_line(std::string act1, std::string act2, std::string act3) {
    print("FragTrap ", this->_name, " ", act1);
    print_line(" ", act2, " ", act3);
}