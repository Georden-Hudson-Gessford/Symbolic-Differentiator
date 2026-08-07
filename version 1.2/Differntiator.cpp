#include <iostream>
#include <string>
#include "Poly_differ.h"
#include "chain.h"
constexpr std::string::size_type not_found = std::string::npos;
// g++ Differentiator.cpp  Poly_differ.cpp Route.cpp chain.cpp Parser.cpp -o ex


//Function finds coefficients of expression for outer function
std::string co_finder(std::string& e) {

size_t co_st = e.find_first_of("1234567890");
size_t co_end = e.find_last_of("1234567890");
std::string co = "";

if ( (co_st != not_found && co_end != not_found) && (co_st == co_end))
    co = e.substr(co_st, 1);

else if  ((co_st != not_found && co_end != not_found) && (co_st != co_end))
    co = e.substr(co_st, co_end + 1 );

return co;


}


//sine function differentiator
std:: string sin_diff(std::string& e) {

std::string co = "";

co = co_finder(e);

std::string sign = "";


if (e.substr(0, 1) == "+" || e.substr(0, 1) == "-") 
    sign = e.substr(0,1);

e = sign + co + "cos" ;
return e;
}


//cosine function differentiator
std:: string cos_diff(std::string& e){

std::string co = "";


std::string sign = "";



co = co_finder(e);

if (e.substr(0, 1) == "+" || e.substr(0, 1) == "-") 
    sign = e.substr(0,1);

if (sign == "-")
    sign = "+";
else
    sign = "-";

e = sign + co+ "sin" ;

return e;
}


//tangent function differentiator
std:: string tan_diff(std::string& e) {

std::string co = "";
co = co_finder(e);


std::string sign = "";


if (e.substr(0, 1) == "+" || e.substr(0, 1) == "-") 
    sign = e.substr(0,1);

e = sign + co + "sec^2" ;


return e;
}

//Eulers number differentiator
std:: string e_diff(std::string& e) {

std::string co = "";
co = co_finder(e);


std::string sign = "";


if (e.substr(0, 1) == "+" || e.substr(0, 1) == "-") 
    sign = e.substr(0,1);

e = sign + co + "e^" ;

return e;
}


//Natural Log differentiator
std:: string ln_diff(std::string& e) {

std::string co = "1";
co = co_finder(e);

if (co == "")
    co = "1";

std::string sign = "";


if (e.substr(0, 1) == "+" || e.substr(0, 1) == "-") 
    sign = e.substr(0,1);


e = sign + co + "/" ;
return e;

}


 std::string differentiator(std::string& e) {


 if ( e.find("(") != not_found) 
     return chain_rule(e);
            
 if (e.find("sin") != not_found) 
    return sin_diff(e); 

else if (e.find("e^") != not_found) 
    return e_diff(e);

else if (e.find("cos") != not_found) 
    return cos_diff(e);

else if (e.find("tan") != not_found) 
    return tan_diff(e);

else if (e.find("ln") != not_found) 
    return ln_diff(e);

else if (e.find("x") != not_found) 
    return poly_parse(e);

else
    e = "";


return e;
}



