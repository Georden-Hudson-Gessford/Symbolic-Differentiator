
#include <string>
#include <vector>
#include <cstdlib>


 constexpr std::string::size_type not_found = std::string::npos;

void bad_euler(std::vector<std::string>& e){
     size_t i = 0;

while( i < e.size()) {

size_t e_pos = e[i].find("e^");
 

if ( e_pos != not_found) {
if (e[i][e_pos+2] != '(' && e[i][e_pos+2] != 'x')
e.erase(e.begin() + i);
else
i ++;
}

else{
    i++;

 continue; }
}

}

void x_outside(std::vector<std::string>& e){
     size_t i = 0;

while( i < e.size()) {

size_t x_pos = e[i].find("x(");

if ( x_pos != not_found) 
e.erase(e.begin() + i);
else
i ++;

}
}



void bad_function_destruction(std::vector<std::string>& e){
     size_t i = 0;

while( i < e.size()) {

size_t sec = e[i].find("sec");
size_t arcsin = e[i].find("arcsin");
size_t cotan = e[i].find("cotan");
size_t csc = e[i].find("csc");
size_t log= e[i].find("log");
size_t arccos = e[i].find("arccos");
size_t arctan = e[i].find("arctan");


if ( sec != not_found || csc != not_found || log != not_found ||arcsin != not_found || cotan!= not_found
    || arccos != not_found || arctan != not_found)
e.erase(e.begin() + i);

else
i ++;

}
}


void num_to_x (std::vector<std::string>& e){

size_t i = 0;

while( i < e.size()) {

size_t caret = e[i].find("^");
if (caret != not_found) {
if ( isdigit(e[i][caret-1]) && ( isalpha(e[i][caret+1]) || e[i][caret+1] == '(' )) 
e.erase(e.begin() + i);
else 
i++;
}

else

i++;

}
}

std::vector<std::string> Pruner(std::vector<std::string>& terms) {
    
bad_euler(terms);
x_outside(terms);
num_to_x(terms);
bad_function_destruction(terms);





   return terms;
}
