#include <iostream>
#include <string>
constexpr std::string::size_type not_found = std::string::npos;
typedef size_t pos;




//Function 1
std::string poly_diff(std::string& coefficient, std::string& exponent) {

std::string x = "x";
std::string return_me;
int diff_co;
int expo_co;
int diff_expo;


int co_num = stoi(coefficient);

if ( exponent == "") {
    x = "";

        return coefficient;

}
else 
{
    expo_co = stoi(exponent);

    diff_co = co_num * expo_co;
    diff_expo = expo_co - 1;

   
 }

if (diff_expo == 0)
x = ""; 

if (diff_co > 0)
    coefficient = '+' + std::to_string(diff_co);
else 
    coefficient = std::to_string(diff_co);

exponent = std::to_string(diff_expo);

if ( x == "")
    return_me = coefficient + x;
else if ( x == "x")
    return_me = coefficient + x + "^" + exponent;

return return_me;



}

//Function 2
std::string co_find(std::string& e) {

std::string co;

pos c_po = e.find_first_of("123456789");
pos x_p = e.find("x");

if (c_po == not_found && x_p == not_found)
    {
    e = "1";
    return e;
    }

if (x_p == not_found) 
    {
    co = "";
    return co; 
    } 

if (c_po > x_p) 
    {
    co = "1";
    return co; 
    }

 if ( x_p != not_found)
     co = e.substr(c_po, x_p - c_po);


return co;}


//Function 3
std::string no_caret (std::string& e) {
pos x_p;
 x_p = e.find("x");

if (x_p != not_found) 
  e.erase(x_p, 0); 

else if (x_p == not_found) {
  e = "";
  return e;}

return e;
}




std::string poly_parse(std::string& e) {
pos caret_detector;
 
pos coefficient_pos;

std::string sign;
std::string exponent;
std::string coefficient;
bool first_term = false;

caret_detector = e.find("^");

 if (e[0] == '-' || e[0] == '+') 
        sign = e[0]; 
else 
         sign = "";
        

if (caret_detector == not_found) {
    no_caret (e);

    if( e == "")
        return e;



   }

else if (caret_detector != not_found) {

    exponent = e.substr(caret_detector+1);
     

}

coefficient = sign + co_find(e);


if ( coefficient == "") {
    e = "";
return e;
}



if (exponent == "0")
    e = "";
else
    e = poly_diff(coefficient, exponent);
return e;
}

