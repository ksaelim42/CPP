#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon();

    std::string const& getType();
    void setType(std::string type);
};

void print_line();

void print_line(std::string s);

void print_line(std::string s1, std::string s2);

void print_line(std::string s1, std::string s2, std::string s3);

#endif