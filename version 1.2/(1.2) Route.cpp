#include <string>
#include <vector>
#include "parser.h"
#include "Differentiator.h"
#include <iostream>



std::string mother(std::string& e) {
    
std::vector <std::string> termites;
std::string finale;
termites = Termsplitter(e);

for (size_t i = 0; i < termites.size(); i++)
    termites[i] = differentiator(termites[i]);

for ( const auto& terminus : termites)
    finale = finale + " " + terminus;

return finale;
