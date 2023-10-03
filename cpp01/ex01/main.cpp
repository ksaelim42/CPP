#include "Zombie.hpp"
#include <cstdlib>

static bool    is_digit_str(std::string s)
{
    for (size_t i = 0; i < s.length(); ++i) {
        if (!isdigit(s[i])) {
            std::cout << "input must be only digit :(" << std::endl;
            return false;  // String contains a non-digit character
        }
    }
    return true; // String contains a all-digit character
}

static bool	check_emptyline(std::string s) {
	for (std::string::iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isspace(*it)) {
			return (true);
        }
	}
    std::cout << "input must be only digit :(" << std::endl;
	return (false);
}

int main(void) {
    std::string input;

    //keep a integer to variable in command prompt
    while (true)
    {
        std::cout << "Num of zombie : ";
        std::cin >> input;
        if (!check_emptyline(input)) {
            std::cout << std::endl;
            continue;
        }
        if (is_digit_str(input))
            break;
        std::cout << std::endl;
    }
    int num = std::atoi(input.c_str());

    //allocate num memory on zombie object and setname
    Zombie* zombie = zombieHorde(num, "Mark");

    //check zombieHorde function
    for (int i = 0; i < num; i++) {
        std::cout << "Zomber number " << i + 1 << " : Zombie ";
        zombie[i].announce();
    }
    std::cout << std::endl;

    return 0;
}