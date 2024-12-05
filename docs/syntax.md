# Syntax Guide for C++Safe

C++Safe introduces a modern and concise syntax that enhances C++ by focusing on safety, readability, and productivity. This guide provides an overview of the core syntax and its improvements over standard C++.

---

## Table of Contents

### Part 1: Core Features
1. [Program Structure](#program-structure)  
2. [Variables and Constants](#variables-and-constants)  
3. [Functions](#functions)  
4. [Control Flow](#control-flow)  
5. [Memory Safety](#memory-safety)  
6. [Concurrency](#concurrency)  
7. [Slicing and Ranges](#slicing-and-ranges)  
8. [Inline Testing](#inline-testing)

### Part 2: Advanced Features
9. [Pattern Matching](#pattern-matching)  
10. [Error Handling](#error-handling)  
11. [Named Parameters](#named-parameters)  
12. [Coroutines](#coroutines)  
13. [Modules](#modules)

---

## Part 1: Core Features

### Program Structure

C++Safe eliminates boilerplate code, allowing programs to focus on functionality without unnecessary overhead. Unlike traditional C++ programs, you can avoid verbose `#include` directives and write a cleaner `main` function.

#### Example
```cpp
func main(): void {
    print("Welcome to C++Safe!");
}
```

#### Improvement
- Simplifies the program entry point by removing excessive boilerplate.
- Makes code more readable and closer to modern languages like Python or Swift.

---

### Variables and Constants

#### Variable Declaration

Use `let` for variables and `const` for constants. Type annotations are optional when types can be inferred. This eliminates the verbosity of type declarations in standard C++.

##### Syntax
```cpp
let variableName = value;       // Implicit type
let variableName: Type = value; // Explicit type
const constantName = value;     // Constant value
```

##### Example
```cpp
let age = 25;              // Implicit integer type
let name: string = "Alice"; // Explicit string type
const pi = 3.14159;        // Constant value
```

#### Improvement
- Reduces verbosity by leveraging type inference with `let`.
- Encourages immutability with a concise `const` syntax.

---

### Functions

Functions are declared using the `func` keyword, with optional return type annotations. The syntax is inspired by modern languages, making it concise and easy to read.

#### Syntax
```cpp
func functionName(parameters): ReturnType {
    // Function body
}
```

#### Example
```cpp
func add(a: int, b: int): int {
    return a + b;
}

func greet(): void {
    print("Hello, world!");
}
```

#### Improvement
- Replaces the verbose `returnType functionName()` syntax of C++ with a more concise and modern format.
- Simplifies function declarations and enhances readability.

---

### Control Flow

#### If-Else Statements

C++Safe simplifies conditional statements by removing the need for parentheses, making code cleaner and more intuitive.

##### Syntax
```cpp
if condition {
    // Code block
} else {
    // Code block
}
```

##### Example
```cpp
if x > 10 {
    print("x is greater than 10");
} else {
    print("x is 10 or less");
}
```

#### Improvement
- Eliminates redundant parentheses around conditions, reducing clutter.
- Promotes a clean block structure for better readability.

#### Loops

Loops in C++Safe are designed for simplicity and clarity. The `range` function makes loops more intuitive and reduces boilerplate.

##### Syntax
```cpp
for variable in range(start, end, step) {
    // Code block
}
```

##### Examples
```cpp
for i in range(1, 5) {
    print(i);
}

while x > 0 {
    x -= 1;
}
```

#### Improvement
- Provides a Python-like range function for concise iteration.
- Simplifies the syntax for `for` and `while` loops.

---

### Memory Safety

C++Safe introduces the `safe` keyword to replace raw pointers with smart pointers, ensuring automatic memory management.

#### Syntax
```cpp
let variableName = safe<Type>(value);
```

#### Example
```cpp
let ptr = safe<int>(42);
```

#### Improvement
- Replaces unsafe raw pointers with `std::shared_ptr`.
- Automates memory management, reducing the risk of memory leaks and dangling pointers.

---

### Concurrency

Concurrency in C++Safe is modernized with support for asynchronous programming and threading.

#### Async and Await

##### Syntax
```cpp
async functionName() {
    // Async code
}

let result = await asyncFunction();
```

##### Example
```cpp
async fetchData() {
    let data = await getData();
    print(data);
}
```

#### Improvement
- Introduces a clean and intuitive syntax for asynchronous operations.
- Simplifies working with async tasks compared to standard C++.

#### Threads

##### Syntax
```cpp
thread threadName = spawn {
    // Code to run in thread
};
threadName.join();
```

##### Example
```cpp
thread t = spawn {
    print("Running in a separate thread!");
};
t.join();
```

#### Improvement
- Simplifies thread creation with `spawn`.
- Reduces verbosity of thread management compared to `std::thread`.

---

### Slicing and Ranges

C++Safe introduces Python-style slicing for arrays and intuitive range iteration for loops.

#### Syntax

```cpp
let subArray = array[start:end];  // Slice from start to end-1
for variable in range(start, end, step) {
    // Code block
}
```

#### Example

```cpp
let nums = [1, 2, 3, 4, 5];
let slice = nums[1:4];  // [2, 3, 4]

for i in range(0, 10, 2) {
    print(i);  // 0, 2, 4, 6, 8
}
```

#### Improvement
- Makes slicing arrays straightforward and readable.
- Enhances loop syntax with step-based iteration.

---

### Inline Testing

Inline tests allow developers to validate functionality directly within the code using a simple syntax.

#### Syntax

```cpp
test "test description" {
    assert(condition);
}
```

#### Example

```cpp
test "basic math works" {
    assert(1 + 1 == 2);
}

test "string equality" {
    assert("Hello" == "Hello");
}
```

#### Improvement
- Simplifies writing unit tests with embedded syntax.
- Reduces dependency on external testing frameworks.

---

## Part 2: Advanced Features

### Pattern Matching

#### Syntax

```cpp
match value {
    case (pattern) {
        // Code block
    }
    default_case {
        // Fallback code
    }
}
```

#### Example
```cpp
match(value) {
    case (42) {
        print("Matched: 42");
    }
    case ("Hello") {
        print("Matched: Hello");
    }
    default_case {
        print("No match");
    }
}
```

#### Improvement
- Provides a concise and type-safe alternative to nested `if-else` or `switch` statements.
- Simplifies handling of multiple types or conditions.

---

### Error Handling

#### Syntax

```cpp
let result = riskyOperation();

match result {
    case (int success) {
        // Handle success
    }
    case (string error) {
        // Handle error
    }
}
```

#### Example
```cpp
let result = riskyOperation();

match(result) {
    case (int success) {
        print("Success:", success);
    }
    case (string error) {
        print("Error:", error);
    }
}
```

#### Improvement
- Eliminates the need for exceptions or manual error codes.
- Combines success and error handling into a unified structure.

---

### Named Parameters

#### Syntax

```cpp
func functionName(param1: Type, param2: Type): ReturnType {
    // Function body
}

functionName(param1 = value1, param2 = value2);
```

#### Example
```cpp
func configure(height: int, width: int, color: string): void {
    print("Height:", height, "Width:", width, "Color:", color);
}

configure(height = 100, width = 200, color = "blue");
```

#### Improvement
- Enhances readability by explicitly associating arguments with parameter names.
- Avoids errors from misordered arguments.

---

### Coroutines

#### Syntax

```cpp
func generatorFunction(): coroutine<Type> {
    yield value;
}
```

#### Example
```cpp
func countUpTo(max: int): coroutine<int> {
    for (let i = 0; i <= max; ++i) {
        yield i;
    }
}

for i in countUpTo(5) {
    print(i);
}
```

#### Improvement
- Simplifies coroutine implementation with clean syntax.
- Reduces boilerplate for asynchronous workflows.

---

### Modules

#### Syntax

```cpp
export module moduleName;

import moduleName;
```

#### Example

**math.module.cpp**:
```cpp
export module math;

export func add(a: int, b: int): int {
    return a + b;
}
```

**main.cpp**:
```cpp
import math;

print(add(3, 5));
```

#### Improvement
- Replaces `#

include` with modular imports, improving organization.
- Reduces compile times and eliminates redundancy.

---
