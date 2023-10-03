#include <string>
#include <iostream>

void print_line() {
	std::cout << std::endl;
}

void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_line(std::string* s) {
	std::cout << s << std::endl;
}

int main()
{
    std::string var = "HI THIS IS BRAIN";
    std::string *ptr = &var;
    std::string &ref = var;

    //print memory address
    print_line(&var);
    print_line(ptr);
    print_line(&ref);
    print_line();

    //print value of string
    print_line(var);
    print_line(*ptr);
    print_line(ref);
    return 0;
}