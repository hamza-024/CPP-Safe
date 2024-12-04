# Implementation Guide for C++Safe

This document explains how **C++Safe** features are implemented as an extension of the C++ language. By leveraging the C++ ecosystem, these features are built using macros, templates, and utility functions, ensuring seamless integration with existing C++ tools and libraries.

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

### Implementation
- Simplifies function declarations using macros while ensuring compatibility with C++ standards.

```cpp
#define func auto
```

### Example
```cpp
#include <iostream>

func main() -> int {
    std::cout << "Welcome to C++Safe!" << std::endl;
    return 0;
}
```

### How It Works
- The `func` macro replaces the `auto` keyword for concise function declarations.
- The `main` function retains its standard signature, ensuring compatibility with the C++ standard.

---

## Statements

### Implementation
- Provides concise macros for variable and constant declarations.

```cpp
#define let auto
#define const_ const auto
```

### Example
```cpp
let x = 42;
const_ pi = 3.14159;
```

### How It Works
- The `let` macro maps to `auto`, leveraging C++'s type inference capabilities.
- The `const_` macro ensures immutability while retaining the benefits of type inference.

---

## Expressions

### Implementation
- Introduces a macro for simplified output with variadic arguments.

```cpp
#define print(...) (std::cout << format(__VA_ARGS__) << std::endl)

// Helper function for variadic argument handling
template <typename... Args>
std::string format(Args... args) {
    std::ostringstream oss;
    (oss << ... << args);
    return oss.str();
}
```

### Example
```cpp
print("Sum:", 3 + 5);
```

### How It Works
- The `print` macro uses a helper function (`format`) to concatenate variadic arguments.
- Outputs are sent to `std::cout` and automatically terminated with a newline.

---

## Functions

### Implementation
- Simplifies function declarations and returns using macros.

```cpp
#define func auto
#define ret return
```

### Example
```cpp
func add(int a, int b) -> int {
    ret a + b;
}
```

### How It Works
- The `func` macro provides a cleaner and modern syntax for declaring functions.
- The `ret` macro is shorthand for the `return` keyword, improving code readability.

---

## Control Flow

### Implementation
- Simplifies loops with macros for range-based iteration.

```cpp
#define for_in(var, range) for (auto var : range)
```

### Example
```cpp
std::vector<int> nums = {1, 2, 3, 4, 5};
for_in(num, nums) {
    std::cout << num << std::endl;
}
```

### How It Works
- The `for_in` macro simplifies iterating over STL containers, reducing boilerplate code.

---

## Memory Safety

### Implementation
- Uses smart pointers with a simplified macro to ensure automatic memory management.

```cpp
#define safe(type, ...) std::make_shared<type>(__VA_ARGS__)
```

### Example
```cpp
auto ptr = safe(int, 42);
auto arr = safe(std::vector<int>, std::initializer_list<int>{1, 2, 3});
```

### How It Works
- The `safe` macro wraps `std::make_shared` for creating `std::shared_ptr` instances.
- Memory is automatically managed, reducing the risk of memory leaks or dangling pointers.

---

## Concurrency

### Implementation
- Provides macros to simplify asynchronous tasks and threading.

```cpp
#define async_task std::async
#define spawn(block) std::thread([]() { block; })
```

### Example
```cpp
auto result = async_task(std::launch::async, fetchData);
spawn({
    std::cout << "Running in a separate thread!";
}).join();
```

### How It Works
- The `async_task` macro maps to `std::async` for running tasks asynchronously.
- The `spawn` macro simplifies thread creation and execution, improving readability.

---

## Slicing and Ranges

### Implementation
- Adds slicing and custom range macros for iteration.

```cpp
template <typename T>
std::vector<T> slice(const std::vector<T>& vec, size_t start, size_t end) {
    return {vec.begin() + start, vec.begin() + end};
}

#define range(start, end, step) \
    [](int s, int e, int st) { \
        std::vector<int> r; \
        for (int i = s; i < e; i += st) r.push_back(i); \
        return r; \
    }(start, end, step)
```

### Example
```cpp
std::vector<int> nums = {1, 2, 3, 4, 5};
auto subArray = slice(nums, 1, 4);

for (auto num : range(0, 10, 2)) {
    std::cout << num << " ";
}
```

### How It Works
- The `slice` function extracts a subarray from a vector.
- The `range` macro generates a sequence of integers for iteration.

---

## Inline Testing

### Implementation
- Simplifies testing with macros for test descriptions and assertions.

```cpp
#define test(desc, block) \
    do { \
        std::cout << "Running test: " << desc << std::endl; \
        block; \
    } while (0)

#define assert(condition) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " #condition << std::endl; \
    }
```

### Example
```cpp
test("Basic math works", {
    assert(1 + 1 == 2);
});

test("String comparison", {
    assert("Hello" == "Hello");
});
```

### How It Works
- The `test` macro outputs the test description and runs the associated code block.
- The `assert` macro checks conditions and outputs a success or failure message.
