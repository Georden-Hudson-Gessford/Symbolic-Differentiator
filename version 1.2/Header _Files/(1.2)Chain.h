#ifndef CHAINED_H
#define CHAINED_H


#include <string>
typedef std::string derivative;
typedef std::string original;

std::string factor_finder(std::string& e);

original find_v(std::string& e);


original find_u(std::string& e);

std::string chain_rule(std::string& e);

#endif
