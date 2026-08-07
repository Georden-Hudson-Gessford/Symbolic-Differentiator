# Symbolic Differentiator

A C++ project exploring symbolic differentiation through multiple implementations, from direct expression processing to a compiler-style front end built around tokenization, parsing, and abstract syntax trees.

The goal of this repository is not only to compute derivatives, but to explore how mathematical expressions can be represented, analyzed, transformed, and eventually compiled through increasingly structured software architectures.

## Overview

This repository contains multiple versions of a symbolic differentiation engine.

The earlier implementation approaches differentiation more directly by processing mathematical expressions and identifying their components through custom string manipulation, recursion, and expression-specific logic.

The newer implementation takes a compiler-inspired approach:

```text
Source Expression
      |
      v
  Tokenizer
      |
      v
   Parser
      |
      v
     AST
      |
      v
Symbolic Transformation
      |
      v
 Simplification
      |
      v
Derivative Expression
```

Rather than treating an equation primarily as a string, the compiler-style implementation converts it into a structured representation that can be recursively manipulated.

Each implementation has its own README containing more detailed explanations of its design, supported syntax, current limitations, and usage.

---

## Project Goals

This repository serves several purposes:

* Build a functional symbolic differentiation engine in C++.
* Develop stronger understanding of recursion and tree-based data structures.
* Explore tokenization and parsing.
* Learn compiler front-end architecture.
* Practice memory management using pointers and smart pointers.
* Represent mathematical expressions as abstract syntax trees.
* Implement symbolic transformations over structured expressions.
* Explore expression simplification and algebraic manipulation.
* Compare an organically developed implementation with a more formal compiler-style design.

The project is intentionally evolving from simpler approaches toward more scalable ones.

---

## Repository Structure

The repository contains two main generations of the differentiator.

### Original Symbolic Differentiator

The original implementation was developed around direct manipulation of mathematical expressions.

It explores concepts such as:

* expression splitting
* operator detection
* parentheses handling
* recursive function processing
* polynomial differentiation
* coefficients and powers
* nested expressions
* trigonometric differentiation
* chain-rule handling

This version reflects the process of building a symbolic mathematics engine from first principles without first constructing a formal parser.

Its individual README documents the implementation in greater detail.

### Compiler-Style Symbolic Differentiator

The newer implementation reorganizes the problem around concepts commonly found in compilers and interpreters.

Major components include:

#### Lexer / Tokenizer

Transforms raw mathematical text into a sequence of tokens.

For example:

```text
3*x^2 + 5*x
```

may become conceptually:

```text
NUMBER(3)
MULTIPLY
VARIABLE(x)
POWER
NUMBER(2)
PLUS
NUMBER(5)
MULTIPLY
VARIABLE(x)
```

#### Parser

Consumes tokens according to the grammar of the expression language.

The parser is responsible for concepts such as:

* operator precedence
* associativity
* parentheses
* nested expressions

#### Abstract Syntax Tree

The parser produces a tree representation of the mathematical expression.

For example:

```text
3 * x + 5
```

can be represented conceptually as:

```text
        +
       / \
      *   5
     / \
    3   x
```

This representation makes recursive symbolic transformations much easier to reason about.

#### Symbolic Differentiation

Differentiation rules can then operate directly on AST nodes.

For example:

```text
d/dx (u + v)
```

becomes:

```text
du/dx + dv/dx
```

and

```text
d/dx (u * v)
```

becomes:

```text
u'v + uv'
```

Because expressions are represented structurally, differentiation becomes a tree transformation rather than primarily a string-processing problem.

---

## Why Multiple Implementations?

An important part of this project is comparing different ways of solving the same problem.

The original differentiator demonstrates what happens when symbolic manipulation is built directly around expression strings and specialized algorithms.

The compiler-style implementation introduces stronger abstractions:

```text
text -> tokens -> syntax tree -> transformations
```

This separation makes the system easier to extend as the expression language becomes more complicated.

Keeping both implementations in the repository also preserves the development history of the project and demonstrates the architectural progression from direct manipulation toward a formal language-processing pipeline.

---

## Current and Planned Capabilities

Depending on the implementation, the project explores or intends to support expressions involving:

* constants
* variables
* addition
* subtraction
* multiplication
* division
* powers
* parentheses
* polynomial expressions
* nested expressions
* trigonometric functions
* chain rule
* product rule
* quotient rule

Future development may also include:

* more advanced simplification
* additional mathematical functions
* symbolic evaluation
* improved error reporting
* expression pretty-printing
* constant folding
* canonical expression forms
* additional optimization passes
* code generation

---

## Example

An input expression such as:

```text
5x^3 + 2x^2 - 7x + 4
```

should produce the symbolic derivative:

```text
15x^2 + 4x - 7
```

For a nested expression such as:

```text
sin(3x^4)
```

the derivative requires structural recognition of both the outer and inner expressions:

```text
12x^3 * cos(3x^4)
```

Handling expressions like these is one of the primary motivations for moving toward an AST-based architecture.

---

## Architecture Direction

The long-term architecture of the compiler-style version is approximately:

```text
                 Mathematical Expression
                          |
                          v
                    +-----------+
                    | Tokenizer |
                    +-----------+
                          |
                          v
                    Token Stream
                          |
                          v
                     +--------+
                     | Parser |
                     +--------+
                          |
                          v
                 Abstract Syntax Tree
                          |
                +---------+---------+
                |                   |
                v                   v
        Differentiation         Simplification
                |                   |
                +---------+---------+
                          |
                          v
                  Transformed AST
                          |
                          v
                     Formatter
                          |
                          v
                Symbolic Expression
```

This architecture also creates opportunities for future compiler-like stages such as optimization or code generation.

---

## What This Project Explores

Although the visible result is a symbolic differentiator, the project also serves as a practical introduction to several broader computer science concepts.

### Data Structures

Abstract syntax trees provide practical experience with:

* trees
* recursive structures
* node ownership
* traversal
* recursive algorithms

### Memory Management

The C++ implementation provides opportunities to work with:

* pointers
* references
* `std::unique_ptr`
* ownership semantics
* dynamically constructed trees

### Language Processing

The compiler-style implementation introduces:

* lexical analysis
* token streams
* grammars
* recursive-descent parsing
* operator precedence
* syntax trees

### Algorithms

Symbolic differentiation itself becomes a recursive tree-rewriting problem.

### Software Architecture

The project demonstrates why separating a system into components such as:

```text
Lexer
Parser
AST
Transformer
Simplifier
Printer
```

becomes increasingly important as complexity grows.

---

## Development Philosophy

This repository is intentionally iterative.

The project began with the question:

> How can a program differentiate a mathematical expression?

As the supported expressions became more complicated, that question naturally expanded into others:

* How should mathematical expressions be represented?
* How should operator precedence be handled?
* How can nested expressions be analyzed safely?
* How should recursive transformations be structured?
* When does string manipulation stop scaling?
* Why do compilers use intermediate representations?
* How can the same expression tree support differentiation, simplification, evaluation, or code generation?

The repository documents that progression.

The result is both a symbolic mathematics project and an exploration of compiler construction.

---

## Building

The project is written primarily in C++.

Individual implementations may have different build commands and requirements. Refer to the README inside each project directory for exact instructions.

A typical standalone source file can be compiled with a modern C++ compiler using a command similar to:

```bash
g++ -std=c++17 main.cpp -o differentiator
```

The exact source layout will vary between implementations.

---

## Roadmap

Possible future milestones include:

* [ ] Complete arithmetic-expression parser
* [ ] Add variables to the AST
* [ ] Add exponentiation
* [ ] Implement complete AST-based differentiation
* [ ] Implement product rule
* [ ] Implement quotient rule
* [ ] Implement chain rule
* [ ] Add common trigonometric functions
* [ ] Build an expression simplification pass
* [ ] Improve AST printing
* [ ] Add syntax and error diagnostics
* [ ] Expand test coverage
* [ ] Add expression evaluation
* [ ] Explore intermediate representations
* [ ] Explore assembly or machine-code generation from mathematical expressions

---

## Repository READMEs

This README describes the overall project.

Each major implementation also contains its own README describing:

* architecture
* source files
* supported syntax
* implementation details
* build instructions
* examples
* limitations
* future development

Refer to those documents when exploring a specific version of the differentiator.

---

## Status

This project is under active development.

The repository intentionally contains both earlier and newer approaches as the architecture evolves. Some components may therefore be experimental, incomplete, or replaced by newer designs.

The progression itself is part of the project: moving from direct expression manipulation toward a structured compiler-style symbolic mathematics engine.

