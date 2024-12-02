# Syntax Guide for C++Safe

C++Safe introduces a modern and concise syntax that enhances C++ by focusing on safety, readability, and productivity. This guide provides an overview of the core syntax and its improvements over standard C++.

---

## Table of Contents

1. [Program Structure](#program-structure)  
2. [Variables and Constants](#variables-and-constants)  
3. [Functions](#functions)  
4. [Control Flow](#control-flow)  
5. [Classes and Objects](#classes-and-objects)  
6. [Memory Safety](#memory-safety)  
7. [Concurrency](#concurrency)  

---

## Program Structure

C++Safe eliminates boilerplate code, allowing programs to focus on functionality without unnecessary overhead.

### Example
```cpp
func main(): void {
    print("Welcome to C++Safe!");
}
```

---

## Variables and Constants

### Variable Declaration

Use `let` for variables and `const` for constants. Type annotations are optional when types can be inferred.

#### Syntax
```cpp
let variableName = value;       // Implicit type
let variableName: Type = value; // Explicit type
const constantName = value;     // Constant value
```

#### Example
```cpp
let age = 25;            // Implicit integer type
let name: string = "Alice"; // Explicit string type
const pi = 3.14159;      // Constant value
```

---

## Functions

Functions are declared using the `func` keyword, with optional return type annotations.

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

---

## Control Flow

### If-Else Statements
C++Safe simplifies conditional statements by removing the need for parentheses.

#### Syntax
```cpp
if condition {
    // Code block
} else {
    // Code block
}
```

#### Example
```cpp
if x > 10 {
    print("x is greater than 10");
} else {
    print("x is 10 or less");
}
```

### Loops

#### For Loops
Inspired by Python’s `range` function for simplicity.

```cpp
for variable in range(start, end) {
    // Code block
}
```

#### While Loops
```cpp
while condition {
    // Code block
}
```

#### Examples
```cpp
for i in range(1, 5) {
    print(i);
}

while x > 0 {
    x -= 1;
}
```

---

## Classes and Objects

C++Safe combines class declaration and implementation, reducing redundancy.

#### Syntax
```cpp
class ClassName {
    let variableName: Type;

    func methodName(parameters): ReturnType {
        // Method body
    }
}
```

#### Example
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

C++Safe introduces the `safe` keyword to replace raw pointers with smart pointers, ensuring automatic memory management.

#### Syntax
```cpp
let variableName = safe<Type>(value);
```

#### Example
```cpp
let ptr = safe<int>(42);
```

---

## Concurrency

Concurrency in C++Safe is modernized with support for asynchronous programming and threading.

### Async and Await

#### Syntax
```cpp
async functionName() {
    // Async code
}

let result = await asyncFunction();
```

#### Example
```cpp
async fetchData() {
    let data = await getData();
    print(data);
}
```

### Threads

#### Syntax
```cpp
thread threadName = spawn {
    // Code to run in thread
};
threadName.join();
```

#### Example
```cpp
thread t = spawn {
    print("Running in a separate thread!");
};
t.join();
```

