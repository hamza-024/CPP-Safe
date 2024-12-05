# Tour of C++Safe

Welcome to the **Tour of C++Safe**, where we explore the key features and enhancements of this modern C++ extension. C++Safe builds upon the strengths of C++ while addressing common pitfalls, offering a safer, cleaner, and more productive development experience.

---

## Table of Contents

1. [Program Structure](#program-structure)  
2. [Statements](#statements)  
3. [Expressions](#expressions)  
4. [Functions](#functions)  
5. [Control Flow](#control-flow)  
6. [Memory Safety](#memory-safety)  
7. [Concurrency](#concurrency)  
8. [Slicing and Ranges](#slicing-and-ranges)  
9. [Inline Testing](#inline-testing)

---

## Program Structure

C++Safe simplifies the overall program structure, reducing boilerplate and improving readability. Key improvements include:  
- Eliminating excessive `#include` directives.  
- Supporting concise top-level declarations with modern syntax.

### Example

```cpp
let x = 10;

func main(): void {
    print("Hello, C++Safe!");
}
```

### What's Improved?
- Reduces verbosity in the `main()` function.
- Simplifies variable declarations at the top level.

---

## Statements

Statements in C++Safe are more intuitive and concise. Variable declarations, constants, and expression statements are streamlined to reduce verbosity and enhance clarity.

### Variable Declarations

Use `let` for variable declarations and `const` for immutable variables.

#### Example

```cpp
let x = 42;           // Implicit type
let y: float = 3.14;  // Explicit type
const pi = 3.14159;   // Immutable constant
```

### Expression Statements

Standalone expressions like function calls are supported directly as statements.

#### Example

```cpp
print("Hello, world!");
add(3, 5);
```

---

## Expressions

Expressions in C++Safe are designed to enhance readability and consistency. Simplified literals, identifiers, and function calls make code easier to write and understand.

### Literals

Literals are defined with clarity and Python-inspired syntax for numbers and strings.

#### Example

```cpp
42        // Integer
3.14      // Float
"Hello"   // String
```

### Function Calls

Function calls are concise and consistent, supporting inline expressions.

#### Example

```cpp
let sum = add(3, 5);  // Assign result of function call
print("Sum:", sum);
```

---

## Functions

Functions in C++Safe use a clean and modern syntax inspired by languages like Swift. They include concise declarations with optional type annotations for parameters and return values.

### Example

```cpp
func add(a: int, b: int): int {
    return a + b;
}

func greet(name: string = "World"): void {
    print("Hello,", name);
}
```

#### Usage:
```cpp
print(add(3, 5));  // Output: 8
greet();           // Output: Hello, World
greet("Alice");    // Output: Hello, Alice
```

---

## Control Flow

Control flow constructs in C++Safe emphasize intuitive and readable syntax. Loops and conditional statements are simplified for a better developer experience.

### If-Else Statements

Clean block structures eliminate unnecessary parentheses.

#### Example

```cpp
if x > 0 {
    print("Positive");
} else {
    print("Non-positive");
}
```

### Loops

Python-like `range` and simplified while loops make iteration concise and clear.

#### Example

```cpp
for i in range(1, 5) {  // Iterates over 1 to 4
    print(i);
}

while x > 0 {
    x -= 1;
    print("x:", x);
}
```

---

## Memory Safety

C++Safe ensures memory safety by replacing raw pointers with `safe`, a wrapper around `std::shared_ptr` for automatic memory management.

### Example

```cpp
let ptr = safe<int>(42);
print("Value:", *ptr);

let nums = safe<std::vector<int>>({1, 2, 3});
nums->push_back(4);
print("Numbers:", *nums);
```

---

## Concurrency

C++Safe embraces modern asynchronous programming paradigms with `async`, `await`, and `spawn`.

### Async and Await

#### Example

```cpp
async fetchData() {
    let data = await getData();
    print(data);
}
```

### Threads

Simplify thread creation and management with `spawn`.

#### Example

```cpp
thread t = spawn {
    print("Running in a separate thread!");
};
t.join();
```

---

## Slicing and Ranges

C++Safe introduces Python-inspired slicing for arrays and intuitive range-based iteration.

### Example

```cpp
let nums = [1, 2, 3, 4, 5];
let subArray = nums[1:4];  // Extracts elements from index 1 to 3

for i in range(0, 10, 2) {  // Start, end, step
    print(i);
}
```

---

## Inline Testing

C++Safe simplifies testing by allowing lightweight, inline tests that are easy to write and maintain.

### Example

```cpp
test "addition works" {
    assert(add(2, 3) == 5);
}

test "concatenation" {
    assert("Hello " + "World" == "Hello World");
}
```

#### Usage:
```cpp
// Output:
Test passed: addition works
Test passed: concatenation
```
