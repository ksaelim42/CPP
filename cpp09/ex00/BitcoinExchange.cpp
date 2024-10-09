#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) {
    loadExchangeRates("data.csv");
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl; 
        return; 
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::list<std::string> parts = split(line, '|');
        if (parts.size() != 2 || !isValidDate(parts.front())) {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        } 
        
        double rate = std::atof(parts.back().c_str());
        time_t date = stringToTimestamp(parts.front());
        std::cout << parts.front() << " => " << rate << " = " << rate * _exchangeRate.lower_bound(date)->second << std::endl;
    }
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs){
    *this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &rhs){
    
    // if(this != &rhs){
    //     _exchangeRate = rhs._exchangeRate;
    //     _name = rhs._name;
    //     _buffer.str(rhs._buffer.str());
    // }
    (void)rhs;
    return (*this);
}





// Load exchange rates from a file
void BitcoinExchange::loadExchangeRates(std::string fileName) {
    std::ifstream file(fileName.c_str());
    std::string line, date, rate;

    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::getline(ss, date, ','); std::getline(ss, rate, ',');
        _exchangeRate[stringToTimestamp(date)] = std::atof(rate.c_str());
    }
}

// Split a string by a delimiter
std::list<std::string> BitcoinExchange::split(const std::string &s, char delimiter) {
    std::list<std::string> tokens;
    size_t start = 0, end;

    while ((end = s.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    struct tm tm;
    return strptime(date.c_str(), "%Y-%m-%d", &tm) != NULL;
}

time_t BitcoinExchange::stringToTimestamp(const std::string &date) {
    struct tm tm;
    strptime(date.c_str(), "%Y-%m-%d", &tm);
    return mktime(&tm);
}

