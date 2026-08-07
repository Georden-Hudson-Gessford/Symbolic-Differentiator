
#include <iostream>
#include "Differentiator.h"
#include "parser.h"
#include "Route.h"

constexpr std::string::size_type not_found = std::string::npos;

typedef std::string derivative;
typedef std::string original;
typedef std::string temp;

std::string factor_finder(std::string& e) {
std::cout << "set " << e << "\n";
size_t co_st = e.find_first_of("-1234567890");
size_t co_end = e.find_last_of("1234567890");
std::string co = "";

if ( (co_st != not_found && co_end != not_found) && (co_st == co_end))
    co = e.substr(co_st, 1);

else if  ((co_st != not_found && co_end != not_found) && (co_st != co_end))
    co = e.substr(co_st, co_end + 1);
std::cout << "sepcial fact " << co << "\n";
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

std::string special_factor = "";
std::string outer_exp= "";

original u;
original v;
derivative u_p;
derivative v_p;

std::string answer;
u = find_u(e);
v = find_v(e);

if (u.find("^") != not_found) 
    special_factor = factor_finder(u);


if (special_factor != "") 
{
    int temp = 0;
    temp = stoi(special_factor);
    temp = temp - 1;
    outer_exp = std::to_string(temp);
    outer_exp = "^" + outer_exp;
}

temp duble_u = u;
temp duble_v = v;

v_p = mother(duble_v);

u_p = special_factor + differentiator(duble_u);






v_p.erase(0, v_p.find_first_not_of(" \t\n\r"));
answer = v_p + "*" + u_p + "(" + v + ")" + outer_exp ;
answer = "(" + answer + ")";
return answer;


}
