#include "SedLose.hpp"

int main(int ac, char const *av[])
{
    if (ac != 4)
    {
        print_error_line("Using : ./SedLose <filename> <s1> <s2>");
        return 1;
    }
    SedLose sedlose(av[1]);
    if (!sedlose.replace(av[2], av[3]))
        return 1;
    return 0;
}
