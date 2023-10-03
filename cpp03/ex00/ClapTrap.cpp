#include "ClapTrap.hpp"

//**************************************************//
//-------------- Constructor/Destructor ------------//
//**************************************************//

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    print_clapTrap_line("is coming");
    print_line("  Name : ", this->_name);
    print_line("    HP : ", ft_itos(this->_hitPoint));
    print_line("    EP : ", ft_itos(this->_energyPoint));
    print_line("Damage : ", ft_itos(this->_attackDamage));
    print_line();
}

ClapTrap::ClapTrap(const ClapTrap &ref) : _name(ref._name)
, _hitPoint(ref._hitPoint), _energyPoint(ref._energyPoint), _attackDamage(ref._attackDamage) {
    print("Copy of");
    print(" ");
    print_clapTrap_line("is coming");
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref) {
    print("Copy of");
    print(" ");
    print_clapTrap_line("is coming", "** with assignment operator(=) **");
    if (this != &ref) {
        this->_name = ref._name;
        this->_hitPoint = ref._hitPoint;
        this->_energyPoint = ref._energyPoint;
        this->_attackDamage = ref._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    print_line();
    print_clapTrap_line("waving hand... :)");
}


//**************************************************//
//----------- Public Main member function ----------//
//**************************************************//

void ClapTrap::attack(const std::string& target) {
    if (!checkPoint())
        return;
    this->_energyPoint -= 1;
    print_clapTrap("attack");
    print(" ");
    print_line(target, " to lose ", ft_itos(this->_attackDamage), " hitpoit T^T");
}

void ClapTrap::takeDamage(unsigned int amount) {
    print_clapTrap_line("take", ft_itos(amount), "damage ToT");
    this->_hitPoint -= amount;
    if (this->_hitPoint <= 0)
        print_clapTrap_line("is Died x_x");
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!checkPoint())
        return;
    this->_energyPoint -= 1;
    this->_hitPoint += amount;
    print_clapTrap_line("get", ft_itos(amount), "hitPoint ^_^");
}


//**************************************************//
//---------- Public Add on member function ---------//
//**************************************************//

std::string ClapTrap::getname() {
    return this->_name;
}

int ClapTrap::getDamage() {
    return this->_attackDamage;
}

int ClapTrap::getHP() {
    return this->_hitPoint;
}

int ClapTrap::getEP() {
    return this->_energyPoint;
}

bool ClapTrap::checkPoint()
{
    if (this->_energyPoint <= 0 || this->_hitPoint <= 0) {
        if (this->_energyPoint <= 0)
            print_clapTrap_line("out of energy");
        if (this->_hitPoint <= 0)
            print_clapTrap_line("out of hitPoint");
        return false;
    }
    return true;
}

void ClapTrap::attack(ClapTrap &target) {
    attack(target.getname());
    target.takeDamage(this->getDamage());
}

void ClapTrap::upDamage(int amount) {
    this->_attackDamage += amount;
    print_clapTrap_line("power up", ft_itos(amount), "attack damage ^^");
}



void ClapTrap::print_clapTrap(std::string act) {
    print("ClapTrap ", this->_name, " ", act);
}

void ClapTrap::print_clapTrap(std::string act1, std::string act2) {
    print("ClapTrap ", this->_name);
    print(" ", act1, " ", act2);
}

void ClapTrap::print_clapTrap_line(std::string act) {
    print_line("ClapTrap ", this->_name, " ", act);
}

void ClapTrap::print_clapTrap_line(std::string act1, std::string act2) {
    print("ClapTrap ", this->_name);
    print_line(" ", act1, " ", act2);
}

void ClapTrap::print_clapTrap_line(std::string act1, std::string act2, std::string act3) {
    print("ClapTrap ", this->_name, " ", act1);
    print_line(" ", act2, " ", act3);
}


//**************************************************//
//----------------- Add on function ---------------//
//**************************************************//

std::string ft_itos(int i) {
    std::ostringstream oss;
    oss << i;
    return oss.str();
}

void print(std::string s) {
	std::cout << s;
}

void print(std::string s1, std::string s2) {
	print(s1);
    print(s2);
}

void print(std::string s1, std::string s2, std::string s3) {
	print(s1, s2);
    print(s3);
}

void print(std::string s1, std::string s2, std::string s3, std::string s4) {
	print(s1, s2, s3);
    print(s4);
}

void print_line(void) {
	std::cout << std::endl;
}

void print_line(std::string s) {
	print(s);
    print_line();
}

void print_line(std::string s1, std::string s2) {
	print(s1, s2);
    print_line();
}

void print_line(std::string s1, std::string s2, std::string s3) {
    print(s1, s2, s3);
    print_line();
}

void print_line(std::string s1, std::string s2, std::string s3, std::string s4) {
    print(s1, s2, s3, s4);
    print_line();
}

void print_intro(std::string name1, std::string name2) {
    print_line();
    print_line("=======================");
    print_line("|------- Round 1 ------|");
    print("|   ", name1, " VS ", name2);
    print_line("  |");
    print_line("=======================");
    print_line();
}

void print_end(std::string name){
    print_line();
    print_line("The Winner is: ", name);
}