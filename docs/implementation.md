# Implementation Guide for C++Safe

This document explains how **C++Safe** features are implemented as an extension of the C++ language. By leveraging the C++ ecosystem, these features are built using macros, templates, and utility functions, ensuring seamless integration with existing C++ tools and libraries.

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

### Implementation
- **C++Safe** simplifies the program structure by redefining the `main` function syntax using macros.
- This abstraction ensures compatibility with the standard C++ entry point while allowing cleaner syntax for developers.

```cpp
#define func auto
#define main void main_function()
```

### Example
```cpp
func main {
    std::cout << "Welcome to C++Safe!" << std::endl;
}
```

### How It Works
- The `main` function macro (`main_function`) ensures the program compiles and runs correctly with standard C++ compilers.
- Developers get a cleaner, high-level syntax without disrupting the C++ runtime environment.

---

## Statements

### Implementation
- Variable and constant declarations are simplified using macros.
- These macros map directly to C++’s `auto` type inference system.

```cpp
#define let auto
#define const_ const auto
```

### Example
```cpp
let x = 42;         // Variable with inferred type
const_ pi = 3.1415; // Constant with inferred type
```

### How It Works
- The `let` macro uses `auto` to infer types at compile time.
- The `const_` macro enforces immutability while leveraging C++’s type system.

---

## Expressions

### Implementation
- Expression statements like `print` are implemented using variadic macros.
- This allows concatenation of multiple values and redirection to `std::cout`.

```cpp
#define print(...) (std::cout << ... << __VA_ARGS__) << std::endl
```

### Example
```cpp
print("Sum:", 3 + 5);
```

### How It Works
- The macro uses C++ fold expressions (`...`) to handle multiple arguments.
- Outputs are compatible with standard I/O streams.

---

## Functions

### Implementation
- Function definitions are abstracted using macros for a modern syntax.
- The `func` macro aligns with C++’s type inference and return type declaration.

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
- The `func` macro provides a cleaner way to declare functions.
- Standard C++ return types and function definitions ensure compatibility.

---

## Control Flow

### Implementation
- Conditional statements are simplified by wrapping C++ syntax with macros.
- For loops leverage range-based iteration.

```cpp
#define if_ if
#define else_ else

#define for_in(var, range) for (auto var : range)
```

### Example
```cpp
if_ (x > 0) {
    print("x is positive");
} else_ {
    print("x is non-positive");
}

std::vector<int> nums = {1, 2, 3, 4, 5};
for_in(num, nums) {
    print(num);
}
```

### How It Works
- The `if_` and `else_` macros directly map to native C++ constructs.
- The `for_in` macro simplifies iteration over STL containers.

---

## Classes

### Implementation
- Class definitions and member variables are streamlined using macros.

```cpp
#define class_ class
#define let auto
```

### Example
```cpp
class_ Point {
public:
    let x, y;

    func move(int dx, int dy) -> void {
        x += dx;
        y += dy;
    }
};
```

### How It Works
- The `class_` macro maps to C++’s `class` keyword, and `let` is reused for variable declarations.
- Member functions remain standard C++.

---

## Memory Safety

### Implementation
- Memory safety is implemented using `std::shared_ptr` and templates.

```cpp
#define safe(type, value) std::make_shared<type>(value)
```

### Example
```cpp
auto ptr = safe<int>(42);  // Creates a shared_ptr<int> with value 42
```

### How It Works
- The `safe` macro wraps `std::make_shared`, ensuring compatibility with C++’s smart pointer ecosystem.

---

## Concurrency

### Implementation
- Asynchronous operations and threads are abstracted using macros and `std::async`.

```cpp
#define async std::async
#define await std::future
#define spawn(block) std::thread([]() { block; })
```

### Example
```cpp
auto fetchData = async(std::launch::async, []() {
    return "Data fetched!";
});
print(await(fetchData).get());

spawn({
    print("Running in a separate thread!");
}).join();
```

### How It Works
- `async` and `await` map directly to `std::async` and `std::future`.
- `spawn` simplifies thread creation and ensures compatibility with `std::thread`.

---

## Slicing and Ranges

### Implementation
- Slicing and range-based iteration are implemented using templates and utility functions.

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
auto subArray = slice(nums, 1, 4);  // [2, 3, 4]

for_in(i, range(0, 10, 2)) {
    print(i);  // 0, 2, 4, 6, 8
}
```

### How It Works
- The `slice` function extracts a subarray from a vector.
- The `range` macro generates ranges for iteration.

---

## Inline Testing

### Implementation
- Testing is implemented using macros for lightweight assertion and test descriptions.

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
- `test` and `assert` macros integrate seamlessly into standard C++ projects.
- Results are outputted to the console for easy debugging.

---
