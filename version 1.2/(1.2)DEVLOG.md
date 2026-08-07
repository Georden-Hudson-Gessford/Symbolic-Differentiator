

# Version 1.2

## 2026-06-17 (Ideation)
* The strategy for decomposition will be to handle cases with their own function. 
* Constants may have a function, polynomial terms, trigonometric functions. 
* That function will return it and build into the string. 

## 2026-07-03 (Development start)
*finish by 7-15-26 with chain rule and trigonometric implementation

### Newly completed
* Added a function to detect parentheses. This will be useful for detecting chain rule.
  
### Notes
* (Because terms are split by either + or -, any inner function containing signs must not be confused for a new term
* EX: (5x+4+3)^2
* So I will have the termsplitting function ignore information squeezed between parentheses

  ## 2026-07-04
  
  ### Newly completed
  *Created function to find all +,-
  
  ## 2026-07-06
  
  ### Newly completed
  * Created 2 functions to eliminate signs that are not seperating terms (in parentheses and after exponents ^ )
  * Setup debugging and test cases as two separate text files. Will start 3rd text file to document bug history.
  ### Notes
  
  * I need to do a little cleanup work in my code, also make seperate files if i remember how to do that.
  * It would also be easy if there is a way to run multiple test cases.
  * Using functions as debuggers will organize what i am printing, bools can also be used so i can enter and exit debug mode for different functions
  * A vector list for test cases?
  ### Next Steps
  * Next create a file for the parsing process, another file for debugging and  another that can run test cases. ++

## 2026-07-07

### Newly completed

* I have created proper header files and will have a main file, parser file, and differentiator file.
* Created a function to split terms
  
 ### Decisions
 
* I have made the decision that expressions the calculator cannot handle will be pruned instead of shutting down
* I think this will include cases such as csc(x), a^x, (sin(x)^-1, arcsin(x), logs, products, division (even if not quotient rule), fractional or decimal coefficients
* Also includes unsimplified expressions such as 4^3 or 500(3x^2)^4.
  
### Notes
* I think chain rule will be treated recursively



## 2026-07-08

### Problems

  * I am looking to move slower with the pruning function
  * It requires a great deal of recursion i am unfamiliar with  and is on a scale i have yet to deal with
  * I am going to move slower with this process and take time to learn better structures and a way to analyze before it becomes catastrophic.
    
### Notes

  * I am aiming to combine functions and minimize code
  * Prevent copying strings of vectors when i implement recursion
  * Utilize a depth counter for nesting
  * tokenization??
  * Full overview before continuing and resume programming beyond today.

## 2026-07-10

### Newly completed

* Converted 5 functions into 1 whilst reducing size by approx 150 lines.
* Using a depth counter and searching char by char is more efficient (This was the change)

## 2026-07-11 

### Newly completed

*Added function to differentiate polynomials

### Notes

* Ran test cases including x, -x x^1 3x^-4 x^0 etc and all results ran well
*  it can easily recieve from the termsplitter function
  
### Next Steps 

* next will be creating differentiatiors of sin, cos, tan, ln, e, whilst managing signs and coefficients
* so d/dx -5cos = 5sin
* right now a + is added for a positive polynomial but in the end i will remove a + if it is the very first output of the final expression (after all operations)
* so that will be done in main.
  
  ### Notes
  
* Note: a chain rule such as (-e^(3x^4 + sin(x)) will be treated as u = -e^, v = (3x^4+sin(x)). v will split terms and differentiate with sin(x) calling chain
* v' * u'(v)
* e^-() will be considered as a bad case as the negative was not distributed and simplified
  
  ### Next Steps
  
* A pruning function to delete these terms will be created.
* The pruner will likely not accoutn for all cases..
* A product rule should have both the term on the left and right removed, i have decided against implementing this
* Same for quotient rule
* e^-() will be accounted in the pruner. functions of coefficients will be dealt with
* a^x will be destroyed, nested inverse functions are unsimpliifed but will not be pruned I.E e^(ln(x)+x)
* Other decisions will be made for the fate of unsupported functions

 ## 2026-07-11
 
 ### Newly completed
 
* Created functions to differentiate sin and cos
* setup other differentiation functions
  
### Decisions

* sin^2 will not be accepted and must be written as (sin)^2 for chain rule
* Tomorrow the rest of functions will be written (tan,ln,e) and then pruning function will begin 

## 2026-07-12

### Newly completed

* tan, ln,e differentiation finished
  
### Next Steps

* Much of the code for each differentiation is exactly the same so i will create another function to offload those segments
  
### Notes

* organized the differentiation function to help catch unpruned functions just in case
* I saw the opportunity for it to help a little bit through some decisions and decided it was helpful this way
* I might be able to remove some code from the polynomial differentiator as a result as simple coefficients will already be removed.

## 2026-07-13 to 2026-07-14

### Newly completed

  *Everything is finished and recursion for chain rule is working although the result is a little crude to read but is accurate
  
### Next Steps

  *7/15 will be spent optimizing and creating  a pruning function as well as testing
  *Beyond that point active development should end
  *I will try and make e^x valid instead of having to be written e^(x)
  *A menu explaining how to input will be created to  opened from main.

  ## 2026-07-15
  
  ### Newly completed

  * Improved code readibility
  * Added menu function
  *  created a coefficient finder for the differentiator file.
  * The file originally had each function with a segment of identical code for coeffiicents, so I made that piece a function they call on.
    
  ### Problems
  
  * A scare occured when i realized functions such as (   )^4 could not be handled which is a very common case of chain rule
  * Luckily i was very easily able to add this functionality through just a  few lines of code in the chain rule function
  * Improved readibility of the output, though chain rule is not kind on the eyes with highly nested functions

  ### Notes
  
  * Fixed an issue where signs between some polynomials were ++ instead of +
  * Fixed an issue where large coeffiicents of functions were losing digits I.E 500cos was -50sin instead of -500sin
  * On 7/16 I will update  thereadme
    
  ### Next steps
  
  * Their is some more precise cleanup to be done that cannot be ignored
  * I will also write about the future of this project
  7/16 (Development end)
