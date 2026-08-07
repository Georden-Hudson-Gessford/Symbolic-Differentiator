#include <string>
#include <vector>
#include "Parser.h"
#include "Differentiator.h"
#include "Route.h"
#include <iostream>



std::string recursive_route(std::string& e) {
    
std::vector <std::string> parsed_terms;
std::string finale;
parsed_terms = parse_terms(e);

for (size_t i = 0; i < parsed_terms.size(); i++)
    parsed_terms[i] = main_differentiator(parsed_terms[i]);

for ( const auto& terms: parsed_terms)
    finale = finale + " " + terms;

return finale;






}
