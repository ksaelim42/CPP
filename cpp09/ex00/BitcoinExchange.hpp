#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange {
     private:
        std::map<std::time_t, double> _exchangeRate;
        void loadExchangeRates(std::string fileName);
        static std::list<std::string> split(const std::string &s, char delimiter);
        static bool isValidDate(const std::string &date);
        static time_t stringToTimestamp(const std::string &date);
    public:
        BitcoinExchange(std::string filename);
        // BitcoinExchange();
        BitcoinExchange & operator=(BitcoinExchange const &r);
        BitcoinExchange(BitcoinExchange const &r);
        ~BitcoinExchange() {};
    
};


#endif