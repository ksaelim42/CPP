#include "Zombie.hpp"

// Zombie::Zombie(std::string name) {
//     this->_name = name;
// }

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie(void) {
    _name = "Unknow";
}

Zombie::~Zombie(void)
{
    std::cout << _name << " died x_x (has been destoryed)"<< std::endl;
}

void Zombie::announce(void) {
    std::cout << "Zombie_"<< _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
