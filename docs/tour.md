# Tour of C++Safe

Welcome to the **Tour of C++Safe**, where we explore the key features and enhancements of this modern C++ extension. C++Safe builds upon the strengths of C++ while addressing common pitfalls, offering a safer, cleaner, and more productive development experience.

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

---

## Program Structure

C++Safe simplifies the overall program structure, reducing boilerplate and improving readability. Key improvements include:  
- Eliminating excessive `#include` directives.  
- Supporting concise top-level declarations.

### Example

```cpp
let x = 10;

func main(): void {
    print("Hello, C++Safe!");
}
```

---

## Statements

Statements in C++Safe are more intuitive and concise. Variable declarations, constants, and expression statements are streamlined to reduce verbosity.

### Variable Declarations

- Use `let` for variable declarations.  
- Use `const` for immutable variables.

#### Example

```cpp
let x = 42;           // Implicit type
const pi = 3.14159;   // Constant value
```

### Expression Statements

Standalone expressions like function calls are supported.

#### Example

```cpp
print("Hello, world!");
```

---

## Expressions

Expressions in C++Safe enhance readability and consistency with simplified literals, identifiers, and function calls.

### Literals

Literals are defined with clarity and Python-inspired syntax for numbers and strings.

#### Example

```cpp
42        // Integer
3.14      // Float
"Hello"   // String
```

### Function Calls

Function calls are concise and consistent.

#### Example

```cpp
print("Sum:", add(3, 5));
```

---

## Functions

Functions in C++Safe use a clean and modern syntax inspired by languages like Swift.

### Features

- `func` keyword for declarations.  
- Optional type annotations for parameters and return values.

#### Example

```cpp
func add(a: int, b: int): int {
    return a + b;
}
```

---

## Control Flow

Control flow constructs are simplified for readability, with an emphasis on intuitive syntax.

### If-Else Statements

Eliminates redundant parentheses and embraces clean block structures.

#### Example

```cpp
if x > 0 {
    print("Positive");
} else {
    print("Non-positive");
}
```

### Loops

Features Python-like `range` for loops and simplified while loops.

#### Example

```cpp
for i in range(1, 5) {
    print(i);
}

while x > 0 {
    x -= 1;
}
```

---

## Classes

Class definitions in C++Safe combine declaration and implementation into a single construct, enhancing encapsulation and reducing complexity.

### Example

```cpp
class Point {
    let x: int;
    let y: int;

    func move(dx: int, dy: int): void {
        x += dx;
        y += dy;
    }
}
```

---

## Memory Safety

C++Safe ensures memory safety by replacing raw pointers with smart pointers through the `safe` keyword.

### Example

```cpp
let ptr = safe<int>(42); // Automatic memory management
```

---

## Concurrency

Concurrency in C++Safe embraces modern asynchronous programming paradigms with `async`, `await`, and `spawn`.

### Async and Await

#### Example

```cpp
async fetchData() {
    let data = await getData();
    print(data);
}
```

### Threads

#### Example

```cpp
thread t = spawn {
    print("Running in a separate thread!");
};
t.join();
```
