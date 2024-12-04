# Examples for C++Safe

This folder contains example programs demonstrating various features of **C++Safe**. Each example focuses on a specific feature, showcasing the code, expected output, and how it improves upon standard C++.

---

## How to Compile and Run

### Prerequisites
Ensure `g++` is installed on your system:
- **Linux/MacOS**: Use `sudo apt install g++` or `brew install gcc`.
- **Windows**: Install `g++` via [MinGW](https://www.mingw-w64.org/) or a similar tool.

### Compilation
To compile an example file:
```bash
g++ -o <output_name> <file_name>.cpp
```
For example:
```bash
g++ -o program_structure program_structure.cpp
```

### Execution
Run the program as follows:
```bash
./<output_name>
```

---

## Example Files

### 1. `program_structure.cpp`
**Implements**: Simplified Program Structure  
**Description**: Demonstrates how to simplify function declarations with the `func` macro.

**Code**:
```cpp
#include <iostream>

// Macro for cleaner function declarations
#define func auto

func main() -> int {
    std::cout << "Welcome to C++Safe!" << std::endl;
    return 0;
}
```

**Expected Output**:
```
Welcome to C++Safe!
```

**Improvements**:
- Simplifies the function declaration syntax (`func` replaces `auto`).
- Keeps compatibility with standard C++ function requirements.

---

### 2. `statements.cpp`
**Implements**: Variable and Constant Declarations  
**Description**: Highlights the `let` and `const_` macros for concise declarations.

**Code**:
```cpp
#include <iostream>

#define let auto
#define const_ const auto

int main() {
    let x = 42;
    const_ pi = 3.14159;

    std::cout << "x: " << x << ", pi: " << pi << std::endl;
    return 0;
}
```

**Expected Output**:
```
x: 42, pi: 3.14159
```

**Improvements**:
- Replaces verbose type declarations with concise macros.
- Promotes clean, readable code without sacrificing type inference.

---

### 3. `expressions.cpp`
**Implements**: Simplified Expressions  
**Description**: Demonstrates the `print` macro for streamlined output.

**Code**:
```cpp
#include <iostream>
#include <sstream>

#define print(...) (std::cout << format(__VA_ARGS__) << std::endl)

// Helper function for variadic arguments
template <typename... Args>
std::string format(Args... args) {
    std::ostringstream oss;
    (oss << ... << args);
    return oss.str();
}

int main() {
    print("Sum:", 3 + 5);
    return 0;
}
```

**Expected Output**:
```
Sum: 8
```

**Improvements**:
- Replaces `std::cout` chaining with a single macro.
- Supports variadic arguments for flexible, cleaner output.

---

### 4. `functions.cpp`
**Implements**: Simplified Functions  
**Description**: Demonstrates the `func` macro for concise declarations.

**Code**:
```cpp
#include <iostream>

#define func auto
#define ret return

func add(int a, int b) -> int {
    ret a + b;
}

int main() {
    std::cout << "Sum: " << add(3, 5) << std::endl;
    return 0;
}
```

**Expected Output**:
```
Sum: 8
```

**Improvements**:
- Simplifies function declarations with `func`.
- Introduces `ret` as a shorthand for `return`.

---

### 5. `control_flow.cpp`
**Implements**: Enhanced Loop Syntax  
**Description**: Simplifies range-based iteration with the `for_in` macro.

**Code**:
```cpp
#include <iostream>
#include <vector>

#define for_in(var, range) for (auto var : range)

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    for_in(num, nums) {
        std::cout << num << " ";
    }
    return 0;
}
```

**Expected Output**:
```
1 2 3 4 5
```

**Improvements**:
- Reduces boilerplate in `for` loops for STL containers.

---

### 6. `memory_safety.cpp`
**Implements**: Memory Safety  
**Description**: Demonstrates safe pointers with the `safe` macro.

**Code**:
```cpp
#include <iostream>
#include <memory>
#include <vector>

#define safe(type, ...) std::make_shared<type>(__VA_ARGS__)

int main() {
    auto ptr = safe(int, 42);
    std::cout << "Value: " << *ptr << std::endl;

    auto arr = safe(std::vector<int>, std::initializer_list<int>{1, 2, 3});
    std::cout << "Array: ";
    for (const auto& num : *arr) {
        std::cout << num << " ";
    }
    return 0;
}
```

**Expected Output**:
```
Value: 42
Array: 1 2 3
```

**Improvements**:
- Replaces raw pointers with smart pointers for automatic memory management.

---

### 7. `concurrency.cpp`
**Implements**: Simplified Concurrency  
**Description**: Uses `async_task` and `spawn` macros for asynchronous programming and threading.

**Code**:
```cpp
#include <iostream>
#include <thread>
#include <future>

#define async_task std::async
#define spawn(block) std::thread([]() { block; })

int fetchData() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    auto result = async_task(std::launch::async, fetchData);
    std::cout << "Async result: " << result.get() << std::endl;

    spawn({
        std::cout << "Running in a thread!" << std::endl;
    }).join();

    return 0;
}
```

**Expected Output**:
```
Async result: 42
Running in a thread!
```

**Improvements**:
- Simplifies async task and thread creation for modern C++.

---

### 8. `slices_ranges.cpp`
**Implements**: Slicing and Ranges  
**Description**: Simplifies data manipulation and iteration.

**Code**:
```cpp
#include <iostream>
#include <vector>

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

int main() {
    auto subArray = slice(std::vector<int>{10, 20, 30, 40, 50}, 1, 4);
    for (auto num : subArray) std::cout << num << " ";

    for (auto i : range(0, 10, 2)) std::cout << i << " ";
    return 0;
}
```

**Expected Output**:
```
20 30 40
0 2 4 6 8
```

**Improvements**:
- Introduces Python-like slicing and custom ranges.

---

### 9. `inline_testing.cpp`
**Implements**: Inline Testing  
**Description**: Demonstrates `test` and `assert` macros for lightweight tests.

**Code**:
```cpp
#include <iostream>

#define test(desc, block) \
    do { \
        std::cout << "Test: " << desc << std::endl; \
        block; \
    } while (0)

#define assert(condition) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " #condition << std::endl; \
    }

int main() {
    test("Addition works", {
        assert(1 + 1 == 2);
    });

    return 0;
}
```

**Expected Output**:
```
Test: Addition works
```

**Improvements**:
- Adds inline testing with minimal effort for debugging and validation.

