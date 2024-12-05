# Grammar Specification for C++Safe

This document provides a formal grammar for the **C++Safe** programming language using Extended Backus-Naur Form (EBNF). It defines the syntax rules for various constructs in the language and explains how they improve upon standard C++.

---

## Table of Contents

### Part 1: Core Features
1. [Program Structure](#program-structure)
2. [Statements](#statements)
3. [Expressions](#expressions)
4. [Functions](#functions)
5. [Control Flow](#control-flow)
6. [Memory Safety](#memory-safety)
7. [Concurrency](#concurrency)
8. [Slicing and Ranges](#slicing-and-ranges)
9. [Inline Testing](#inline-testing)

### Part 2: Advanced Features
10. [Pattern Matching](#pattern-matching)
11. [Error Handling](#error-handling)
12. [Named Parameters](#named-parameters)
13. [Coroutines](#coroutines)
14. [Modules](#modules)

---

## Part 1: Core Features

### Program Structure

C++Safe improves the program structure by focusing on readability and eliminating boilerplate. It allows a cleaner top-level organization without requiring extensive use of `#include` directives or verbose main function syntax.

```ebnf
Program         ::= Statement+
Statement       ::= VariableDeclaration
                 | FunctionDeclaration
                 | ControlFlowStatement
                 | ExpressionStatement
                 | MemorySafetyStatement
                 | TestStatement
```

---

### Statements

C++Safe introduces a more intuitive and concise syntax for variable declarations and expression-based statements.

#### Variable Declarations

```ebnf
VariableDeclaration ::= "let" Identifier (":" Type)? "=" Expression ";"
ConstantDeclaration ::= "const" Identifier (":" Type)? "=" Expression ";"
```

#### Expressions as Statements

```ebnf
ExpressionStatement ::= Expression ";"
```

---

### Expressions

#### Literals

```ebnf
Literal             ::= IntegerLiteral
                      | FloatLiteral
                      | StringLiteral
IntegerLiteral      ::= Digit+
FloatLiteral        ::= Digit+ "." Digit+
StringLiteral       ::= '"' (Character)* '"'
Digit               ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
```

#### Function Calls

```ebnf
FunctionCall        ::= Identifier "(" (Argument ("," Argument)*)? ")"
Argument            ::= Expression
```

---

### Functions

```ebnf
FunctionDeclaration ::= "func" Identifier "(" (Parameter ("," Parameter)*)? ")" (":" Type)? Block
Parameter           ::= Identifier ":" Type
Block               ::= "{" Statement+ "}"
```

---

### Control Flow

#### If-Else Statements

```ebnf
ControlFlowStatement ::= IfStatement
IfStatement          ::= "if" Expression Block ("else" Block)?
```

#### Loops

```ebnf
ControlFlowStatement ::= ForLoop | WhileLoop
ForLoop              ::= "for" Identifier "in" Range Block
WhileLoop            ::= "while" Expression Block
Range                ::= "range" "(" Expression "," Expression ("," Expression)? ")"
```

---

### Memory Safety

```ebnf
MemorySafetyStatement ::= "let" Identifier "=" "safe" "<" Type ">" "(" Expression? ")" ";"
```

---

### Concurrency

#### Async and Await

```ebnf
ConcurrencyStatement ::= AsyncFunction
AsyncFunction        ::= "async" Identifier "(" ")" Block
AwaitExpression      ::= "await" Identifier "(" ")"
```

#### Threads

```ebnf
ConcurrencyStatement ::= "thread" Identifier "=" "spawn" Block
```

---

### Slicing and Ranges

#### Syntax

```ebnf
ArraySlice ::= Identifier "[" Integer ":" Integer "]"
Range      ::= "range" "(" Integer "," Integer ("," Integer)? ")"
```

---

### Inline Testing

#### Syntax

```ebnf
TestStatement ::= "test" StringLiteral Block
Assertion     ::= "assert" "(" Expression ")"
```

---

## Part 2: Advanced Features

### Pattern Matching

#### Syntax

```ebnf
PatternMatch       ::= "match" "(" Expression ")" "{" PatternCase+ "default_case" Block "}"
PatternCase        ::= "case" "(" PatternExpression ")" Block
PatternExpression  ::= Literal
                      | Type "(" Identifier ")"
                      | Wildcard
Wildcard           ::= "_"
```

---

### Error Handling

#### Syntax

```ebnf
ResultType       ::= "Result" "<" SuccessType "," ErrorType ">"
MatchResult      ::= "match" "(" Identifier ")" "{" ResultCase+ "}"
ResultCase       ::= "case" "(" SuccessType Identifier ")" Block
                    | "case" "(" ErrorType Identifier ")" Block
```

---

### Named Parameters

#### Syntax

```ebnf
NamedParameterDeclaration ::= Identifier ":" Type
NamedParameterCall        ::= Identifier "=" Expression
```

---

### Coroutines

#### Syntax

```ebnf
CoroutineDeclaration ::= "func" Identifier "(" ParameterList ")" "->" "coroutine" "<" Type ">" Block
YieldStatement       ::= "yield" Expression ";"
```

---

### Modules

#### Syntax

```ebnf
ModuleDeclaration ::= "export" "module" Identifier ";"
ImportStatement   ::= "import" Identifier ";"
```

---

## Example Program

This program demonstrates a combination of **Part 1** and **Part 2** features.

```cpp
export module math;

export func add(a: int, b: int): int {
    return a + b;
}

import math;

func main(): void {
    let result = add(3, 5);
    print("Sum:", result);

    match(result) {
        case (8) {
            print("Matched: 8!");
        }
        default_case {
            print("Matched: something else.");
        }
    }

    test "Addition Test" {
        assert(add(2, 3) == 5);
    }
}
```
