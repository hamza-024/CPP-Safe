# C++Safe Roadmap

This roadmap outlines the planned features and potential future enhancements for **C++Safe** to continue simplifying C++ while maintaining its power and flexibility.

---

## Next Planned Features

### 1. **Pattern Matching**
**Description**: Introduce pattern matching as a concise and powerful alternative to `switch` statements.  
**Planned Syntax**:
```cpp
match (value) {
    case 1:
        print("One");
    case 2:
        print("Two");
    default:
        print("Other");
}
```
**How It Improves C++**:
- Eliminates verbose `switch` syntax.
- Enables more expressive and readable conditional logic.

---

### 2. **Default Method Arguments**
**Description**: Allow default values for function arguments to simplify common use cases.  
**Planned Syntax**:
```cpp
func greet(name: string = "World") -> void {
    print("Hello,", name);
}

greet(); // Output: Hello, World
greet("Alice"); // Output: Hello, Alice
```
**How It Improves C++**:
- Reduces repetitive function overloading for common defaults.
- Enhances readability and ease of use.

---

### 3. **Coroutines**
**Description**: Add native coroutine support for non-blocking asynchronous programming.  
**Planned Syntax**:
```cpp
func example() -> coroutine<int> {
    yield 1;
    yield 2;
    yield 3;
}

for num in example() {
    print(num);
}
```
**How It Improves C++**:
- Provides a cleaner, native way to handle asynchronous and lazy computations.
- Eliminates boilerplate for iterator-based sequences.

---

### 4. **Named Parameters**
**Description**: Allow functions to be called with named parameters to improve readability.  
**Planned Syntax**:
```cpp
func configure(height: int, width: int) -> void {
    print("Height:", height, "Width:", width);
}

configure(height = 100, width = 200);
```
**How It Improves C++**:
- Reduces ambiguity in function calls with multiple parameters.
- Enhances code clarity and maintainability.

---

### 5. **Type-Safe Macros**
**Description**: Replace traditional C++ preprocessor macros with type-safe equivalents that integrate into the language.  
**Planned Syntax**:
```cpp
macro MAX(a, b) -> (a > b ? a : b)

let maxVal = MAX(10, 20);
```
**How It Improves C++**:
- Eliminates common macro pitfalls like unexpected type conversions.
- Ensures compile-time type safety for macro operations.

---
