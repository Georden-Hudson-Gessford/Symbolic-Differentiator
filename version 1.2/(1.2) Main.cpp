#include <iostream> 
#include <vector>
#include <string>
#include "Parser.h"
#include "Poly_differ.h"
#include "Differentiator.h"
#include "chain.h"
#include "Route.h"
#include "Pruner.h"

//g++  Derivative5.cpp Differentiator.cpp  Poly_differ.cpp Route.cpp chain.cpp Parser.cpp Pruner.cpp -o run

void menu() {
std::cout <<"       RULES      \n";
std::cout << "------------------\n";
std::cout << "ALLOWED FUNCTIONS\n";
std::cout << "ln(), e^(), SIN()\n";
std::cout << "TAN(), COS(), polynomial\n";
std::cout << "REMOVED FUNCTIONS\n";
std::cout << "inverse trig func\n";
std::cout << "reciprocal trigs \n";
std::cout << "General logs not ln\n";
std::cout << "no func C^X or X^X\n";
std::cout << "------------------\n";
std::cout << "e^x must be written e^(x)\n";
std::cout << "No product or quotient rules\n";
std::cout << "Chain rule is supported\n";
std::cout << "sin^2(x) must be written (sin(x))^2 \n"; 
std::cout << "     RULES END          \n \n";   


std::cout << "enter an expression to see its derivative\n";
std::cout << "EX: 2x^4 + 3x^4 = 8x^3 + 12x^3\n";



}




int main() 
{

 std::string e;
std::vector<std::string> terms;
std::vector<std::string> diff_terms;
menu();

std::getline(std::cin, e);
size_t prepare = 0;
prepare = e.find_first_not_of(" ");
e.erase(0, prepare);
std::cout<< "the expression is:" << e << "\n";

terms = Termsplitter(e);
terms = Pruner(terms);
for (size_t i = 0; i < terms.size(); i++)
    terms[i] = differentiator(terms[i]);
std::cout << "\n";
std::cout <<"the final expression is ";
for (const auto& expel : terms )
std::cout << expel << " ";





return 0;
}

