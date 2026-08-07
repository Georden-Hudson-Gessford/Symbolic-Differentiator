#include <iostream>
#include "Differentiator.h"
#include "Parser.h"
#include "Route.h"
// g++ chain.cpp Differentiator.cpp  Poly_differ.cpp Route.cpp  Parser.cpp -o we
constexpr std::string::size_type not_found = std::string::npos;

typedef std::string derivative;
typedef std::string original;
typedef std::string temporary_variable;
typedef int temporary_int;

std::string factor_finder(std::string& e) {
size_t co_st = e.find_first_of("-1234567890");
size_t co_end = e.find_last_of("1234567890");
std::string co = "";

if ( (co_st != not_found && co_end != not_found) && (co_st == co_end))
    co = e.substr(co_st, 1);

else if  ((co_st != not_found && co_end != not_found) && (co_st != co_end))
    co = e.substr(co_st, co_end + 1);
return co;


}

original find_v(std::string& e)  {

original v;
int depth = 0;

for (int i = 0; i < e.size(); i++)
 {

    char c = e[i];


        if ( c== ')')
            depth--;

        if (depth > 0) {
            v.push_back(c);
        }
        if ( c == '(')
            depth ++;

        if (depth < 0)
            continue;
}
    
return v;
}


original find_u(std::string& e) {

original u;
int depth = 0;

    for (size_t i = 0; i < e.size(); i++)
    {
    char c = e[i];

    if ( c == '(')
        depth ++;

    if ( c== ')')
        depth--;

    if (depth == 0)
        u.push_back(c);
    else
        continue;

}

    return u; 
}

std::string chain_rule(std::string& e) {

std::string factor = "";
std::string outer_exponent= "";

original u;
original v;
derivative u_prime;
derivative v_prime;

std::string answer;
u = find_u(e);
v = find_v(e);

if (u.find("^") != not_found) 
    factor = factor_finder(u);


if (factor != "") 
{
    temporary_int temp = 0;
    temp = stoi(factor);
    temp = temp - 1;
    outer_exponent = std::to_string(temp);
    outer_exponent = "^" + outer_exponent;
}

temporary_variable d_du = u;
temporary_variable v_dv = v;

v_prime = recursive_route(v_dv);

u_prime = factor + main_differentiator(d_du);






v_prime.erase(0, v_prime.find_first_not_of(" \t\n\r"));
answer = v_prime + "*" + u_prime + "(" + v + ")" + outer_exponent ;
answer = "(" + answer + ")";
return answer;


}

