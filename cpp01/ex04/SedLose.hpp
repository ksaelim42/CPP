#ifndef SEDLOSE_H
#define SEDLOSE_H

#include <string>
#include <iostream>
#include <fstream>

class SedLose
{
private:
    std::string _ifile;
    std::string _ofile;
    std::string _rpstr;

public:
    SedLose(std::string filename);
    ~SedLose();

    bool replace(std::string tofind, std::string toreplace);
    bool readfile(std::ifstream &ifs);
    bool check_emptyfile(std::ifstream &ifs);
    bool writefile();
};

void print(std::string s);

void print_line(std::string s);

void print_error_line(std::string s);

void print_error_line(std::string s1, std::string s2);

void print_line(std::string s1, std::string s2);

void print_line(std::string s1, std::string s2, std::string s3);

void print_line(void);

#endif