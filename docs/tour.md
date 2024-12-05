# Tour of C++Safe

Welcome to the **Tour of C++Safe**, where we explore the key features and enhancements of this modern C++ extension. C++Safe builds upon the strengths of C++ while addressing common pitfalls, offering a safer, cleaner, and more productive development experience.

---

# Part 1: Simple Features (Implemented)
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
---


# Part 2: Advanced Features in C++Safe (Not Yet Implemented)
In **Part 2**, we explore advanced features of C++Safe that address key challenges in C++ development. These solutions aim to simplify code, reduce errors, and enhance productivity by modernizing the language.

## Table of Contents

1. [Pattern Matching](#pattern-matching)  
2. [Error Handling](#error-handling)  
3. [Named Parameters](#named-parameters)  
4. [Coroutines](#coroutines)  
5. [Modules](#modules)  

---

## Pattern Matching

### Problem in C++
C++ lacks native pattern matching, forcing developers to use verbose and error-prone constructs like nested `if-else` or `switch` statements. These are particularly cumbersome when working with `std::variant` or polymorphic types, where you need to manually extract and cast values.

### Solution in C++Safe
C++Safe introduces concise and type-safe pattern matching to simplify conditional logic. The `match` construct allows developers to define cases for specific values or types, including a `default_case` for unmatched conditions.

### Example in C++Safe
```cpp
match(value) {
    case (42) {
        print("Matched: The answer is 42!");
    }
    case ("Hello") {
        print("Matched: Greeting received!");
    }
    default_case {
        print("Matched: Something else.");
    }
}
```

### How It Works
- `match` evaluates a value or type at runtime and executes the corresponding case block.
- Type safety ensures that the matched value conforms to the expected type in each case.
- The `default_case` block handles unmatched values, ensuring comprehensive coverage.

### Improvements
- Reduces verbosity compared to nested `if-else` or `switch`.
- Enhances readability and maintainability, especially with complex data types like `std::variant`.
- Type safety eliminates runtime errors caused by invalid type casts.

---

## Error Handling

### Problem in C++
Error handling in C++ relies heavily on exceptions or error codes. Exceptions introduce performance overhead and can be unpredictable in resource-constrained environments. Error codes, while predictable, often lead to repetitive boilerplate and missed error checks.

### Solution in C++Safe
C++Safe adopts a `Result`-like pattern, inspired by Rust, to handle errors without exceptions. A `Result` type encapsulates either a success value or an error value, making it easy to propagate and check errors.

### Example in C++Safe
```cpp
let result = riskyOperation(true);

match(result) {
    case (int success) {
        print("Success:", success);
    }
    case (string error) {
        print("Error:", error);
    }
}
```

### How It Works
- `Result` is a type-safe union of success and error states.
- `match` evaluates the `Result` and executes the corresponding case block.
- This approach eliminates the need for `try-catch` blocks or manual error code checks.

### Improvements
- Removes the performance and complexity of exceptions.
- Ensures errors are explicitly handled, reducing bugs from missed checks.
- Simplifies error propagation with clean syntax and minimal boilerplate.

---

## Named Parameters

### Problem in C++
C++ functions with multiple parameters can become ambiguous, especially when many arguments have the same type. This makes function calls error-prone and hard to read.

### Solution in C++Safe
Named parameters improve function call readability by explicitly associating values with parameter names. This eliminates ambiguity and reduces errors caused by misordered arguments.

### Example in C++Safe
```cpp
func configure(height: int, width: int, color: string): void {
    print("Height:", height, "Width:", width, "Color:", color);
}

configure(height = 100, width = 200, color = "blue");
```

### How It Works
- Named parameters associate each argument with its parameter name in the function signature.
- The syntax ensures arguments are passed in a clear and explicit manner, regardless of their order.

### Improvements
- Enhances code clarity and maintainability, especially for functions with many parameters.
- Reduces errors caused by incorrect argument order.
- Simplifies API design by encouraging self-documenting function calls.

---

## Coroutines

### Problem in C++
C++ coroutines are powerful but complex to implement. They require significant boilerplate, making them inaccessible for many developers. This limits their adoption for asynchronous workflows.

### Solution in C++Safe
C++Safe abstracts coroutines with simple syntax using `func` and `yield`. This allows developers to focus on logic rather than coroutine mechanics, making asynchronous workflows easier to manage.

### Example in C++Safe
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

### How It Works
- `coroutine<int>` defines a generator that yields values lazily.
- The `yield` statement pauses execution and returns a value to the caller.
- The coroutine resumes execution from where it left off on the next iteration.

### Improvements
- Simplifies coroutine implementation with high-level abstractions.
- Reduces boilerplate, making coroutines accessible to more developers.
- Improves performance by allowing lazy computation and non-blocking workflows.

---

## Modules

### Problem in C++
The traditional `#include` directive is prone to errors like circular dependencies and redundant imports. This can lead to bloated code, slower compile times, and poor project organization.

### Solution in C++Safe
C++Safe introduces a modern module system to replace `#include`. Modules improve project structure, reduce compile times, and eliminate common issues with header files.

### Example in C++Safe

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

### How It Works
- `export module` defines a module that encapsulates related code.
- `import` loads the module in other files without needing header files.
- Modules ensure only the necessary symbols are exposed, improving encapsulation.

### Improvements
- Eliminates redundancy and inefficiencies associated with `#include`.
- Reduces compile times significantly for large projects.
- Encourages better project organization and modular design.

---
