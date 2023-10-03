#include "SedLose.hpp"

SedLose::SedLose(std::string filename) {
    this->_ifile = filename;
    this->_ofile = this->_ifile + ".replace";
}

bool SedLose::readfile(std::ifstream& ifs) {

    if (!ifs.is_open()) {
        print_error_line(this->_ifile, " can't open file :(");
        return false;
    }
    return true;
}

bool SedLose::writefile() {
    std::ofstream ofs(this->_ofile.c_str());

    if (!ofs.is_open()) {
        print_error_line(this->_ofile, " can't open file :(");
        return false;
    }
    ofs << this->_rpstr;
    ofs.close();
    return true;
}

bool SedLose::check_emptyfile(std::ifstream& ifs) {
    if (!std::getline(ifs, this->_rpstr, '\0')) {
        print_error_line("File is empty :(");
        return false;
    }
    return true;
}

bool SedLose::replace(std::string tofind, std::string toreplace) {
    std::ifstream ifs(this->_ifile.c_str());

	if (!readfile(ifs))
		return false;
	if (check_emptyfile(ifs)) {
		size_t pos = 0;
		while ((pos = this->_rpstr.find(tofind, pos)) != std::string::npos) {
			this->_rpstr.erase(pos, tofind.length());
			this->_rpstr.insert(pos, toreplace);
		}
		ifs.close();
		writefile();
	}
	return true;
}

SedLose::~SedLose() {}

void print(std::string s) {
	std::cout << s;
}

void print_line(std::string s) {
	std::cout << s << std::endl;
}

void print_error_line(std::string s) {
	std::cerr << s << std::endl;
}

void print_error_line(std::string s1, std::string s2) {
	std::cerr << s1 << s2 << std::endl;
}

void print_line(std::string s1, std::string s2) {
	std::cout << s1 << s2 << std::endl;
}

void print_line(std::string s1, std::string s2, std::string s3) {
	std::cout << s1 << s2 << s3 << std::endl;
}

void print_line(void) {
	std::cout << std::endl;
}
