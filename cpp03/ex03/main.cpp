#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trap1("Mark");
    ClapTrap trap2("Evaluator");

    print_intro(trap1.getname(), trap2.getname());
    
    {   
        print_line(">> TURN 1");
        trap1.upDamage(1);
        trap1.attack(trap2);
        print_line();
    }

    {
        print_line(">> TURN 2");
        trap2.print_clapTrap_line("very angry (◣‸◢)");
        trap2.upDamage(3);
        trap2.attack(trap1);
        print_line();
    }

    {
        print_line(">> TURN 3");
        trap1.print_clapTrap_line("feels annoyed :(");
        print_line("Because the Damage It doesn't hurt in the slightest.");
        print_line();
        trap1.upDamage(3);
        trap1.print_clapTrap_line("want to defeat his enemies in 1 combo");
        print_line();
        for (size_t i = 0; i < 5; i++) {
            trap1.attack(trap2);
            if (i == 1) {
                print_line();
                trap2.print_clapTrap_line("try to heal himself =_=");
                for (size_t i = 0; i < 5; i++)
                {
                    trap2.beRepaired(1);
                }
                print_line();
            }
        }
    }

    print_end(trap1.getname());
    print_line("He is laughing ◝(ᵔ∀ᵔ)◜");
    print_line("**  Happy ending (Do you think that?) **");
    return 0;
}
