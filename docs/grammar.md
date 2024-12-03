# Grammar Specification for C++Safe

This document provides a formal grammar for the **C++Safe** programming language using Extended Backus-Naur Form (EBNF). It defines the syntax rules for various constructs in the language and explains how they improve upon standard C++.

---

## Table of Contents

1. [Program Structure](#program-structure)
2. [Statements](#statements)
3. [Expressions](#expressions)
4. [Functions](#functions)
5. [Control Flow](#control-flow)
6. [Classes](#classes)
7. [Memory Safety](#memory-safety)
8. [Concurrency](#concurrency)
9. [Slicing and Ranges](#slicing-and-ranges)
10. [Inline Testing](#inline-testing)

---

## Program Structure

C++Safe improves the program structure by focusing on readability and eliminating boilerplate. It allows a cleaner top-level organization without requiring extensive use of `#include` directives or verbose main function syntax.

```ebnf
Program         ::= Statement+
Statement       ::= VariableDeclaration
                 | FunctionDeclaration
                 | ControlFlowStatement
                 | ExpressionStatement
                 | ClassDeclaration
                 | MemorySafetyStatement
```

---

## Statements

C++Safe introduces a more intuitive and concise syntax for variable declarations and expression-based statements.

### Variable Declarations

```ebnf
VariableDeclaration ::= "let" Identifier (":" Type)? "=" Expression ";"
ConstantDeclaration ::= "const" Identifier (":" Type)? "=" Expression ";"
```

### Expressions as Statements

```ebnf
ExpressionStatement ::= Expression ";"
```

---

## Expressions

### Literals

```ebnf
Literal             ::= IntegerLiteral
                      | FloatLiteral
                      | StringLiteral
IntegerLiteral      ::= Digit+
FloatLiteral        ::= Digit+ "." Digit+
StringLiteral       ::= '"' (Character)* '"'
Digit               ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
```

### Function Calls

```ebnf
FunctionCall        ::= Identifier "(" (Argument ("," Argument)*)? ")"
Argument            ::= Expression
```

---

## Functions

```ebnf
FunctionDeclaration ::= "func" Identifier "(" (Parameter ("," Parameter)*)? ")" (":" Type)? Block
Parameter           ::= Identifier ":" Type
Block               ::= "{" Statement+ "}"
```

---

## Control Flow

### If-Else Statements

```ebnf
ControlFlowStatement ::= IfStatement
IfStatement          ::= "if" Expression Block ("else" Block)?
```

### Loops

```ebnf
ControlFlowStatement ::= ForLoop | WhileLoop
ForLoop              ::= "for" Identifier "in" Range Block
WhileLoop            ::= "while" Expression Block
Range                ::= "range" "(" Expression "," Expression ("," Expression)? ")"
```

---

## Classes

```ebnf
ClassDeclaration ::= "class" Identifier "{" ClassBody "}"
ClassBody        ::= (ClassVariable | FunctionDeclaration)*
ClassVariable    ::= "let" Identifier ":" Type ";"
```

---

## Memory Safety

```ebnf
MemorySafetyStatement ::= "let" Identifier "=" "safe" "<" Type ">" "(" Expression? ")" ";"
```

---

## Concurrency

### Async and Await

```ebnf
ConcurrencyStatement ::= AsyncFunction
AsyncFunction        ::= "async" Identifier "(" ")" Block
AwaitExpression      ::= "await" Identifier "(" ")"
```

### Threads

```ebnf
ConcurrencyStatement ::= "thread" Identifier "=" "spawn" Block
```

---

## Slicing and Ranges

### Syntax

- Array slicing uses Python-like `[start:end]` notation.
- Loops support the `range(start, end, step)` function for iteration.

```ebnf
ArraySlice ::= Identifier "[" Integer ":" Integer "]"
Range      ::= "range" "(" Integer "," Integer ("," Integer)? ")"
```

### Example

```cpp
let nums = [1, 2, 3, 4, 5];
let subArray = nums[1:4];  // Extracts elements from index 1 to 3

for i in range(0, 10, 2) { // Start, end, step
    print(i);
}
```

---

## Inline Testing

### Syntax

Tests are declared with the `test` keyword, followed by a string description and a block of assertions.

```ebnf
TestStatement ::= "test" StringLiteral Block
Assertion     ::= "assert" "(" Expression ")"
```

### Example

```cpp
test "basic addition" {
    assert(add(2, 2) == 4);
}

test "string comparison" {
    assert("Hello" == "Hello");
}
```

---

## Example Program

Here is a small example program demonstrating the C++Safe syntax and grammar:

```cpp
func main(): void {
    let x = 10;
    let y: float = 20.5;
    print("Sum:", x + y);

    for i in range(1, 5) {
        print("Iteration:", i);
    }

    if x > 5 {
        print("x is greater than 5");
    } else {
        print("x is 5 or less");
    }

    let result = safe<int>(42);
    print("Safe value:", result);
}
```

