#include <iostream>
#include <vector>
#include <cstring>
#include "parser.h"
using namespace std;


vector<string> Termsplitter (const string& e) {

vector<string> terms;
int depth = 0;
size_t start = 0;
string term;

for (size_t i = 0; i < e.size(); i++) 
{
    
    char c = e[i];

    if ( c == '(')
        depth++;

    else if ( c == ')')  
        depth--;
        

    else if ( (c == '+' || c == '-') && depth == 0) 
    {
        if ( i != 0 && e[i-1] == '^')
        {
            continue;
        }
        
        if ( i == 0)
            continue;

        term = e.substr(start, i - start);
        start = i;
        terms.push_back(term);
    }

}

terms.push_back(e.substr(start));

return terms;
}
