#include "Weapon.hpp"

std::string const& Weapon::getType() {
    return (this->_type);
}

void    Weapon::setType(std::string type) {
    this->_type = type;
}

Weapon::Weapon(std::string type){
    this->_type = type;
}

Weapon::~Weapon() {}

void print_line() {
	std::cout << std::endl;
}

void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void print_line(std::string s1, std::string s2, std::string s3) {
	std::cout << s1 << s2 << s3 << std::endl;
}
