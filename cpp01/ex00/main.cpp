#include "Zombie.hpp"

int main(void)
{
    Zombie unknow;
    unknow.announce();
    Zombie* zombie = new Zombie("Mark");
    zombie->announce();
    delete zombie;

    randomChump("...");
    return 0;
}
