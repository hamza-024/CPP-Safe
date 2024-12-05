# C++Safe

C++Safe is a modern extension of C++ designed to improve safety, simplify syntax, and enhance productivity. It enforces safe memory management and introduces cleaner, user-friendly syntax.

---

## Features

### Part 1: Core Features
- **Automated Memory Safety**: Say goodbye to raw pointers. With `safe`, memory management is simple and secure.
- **Simplified Syntax**: Write more concise and readable code with features like `print` for output.
- **Concurrency**: Leverage modern programming paradigms with macros like `async_task` and `spawn` for asynchronous programming and threading.
- **Powerful Slicing and Ranges**: Simplify data manipulation and iteration with Python-like slicing and custom ranges.
- **Inline Testing**: Add lightweight, inline tests directly into your code for improved debugging and validation.

### Part 2: Advanced Features
- **Pattern Matching**: Simplify conditional logic with type-safe pattern matching for variants and types.
- **Error Handling**: Replace error codes and exceptions with structured, type-safe `Result` patterns.
- **Named Parameters**: Improve function readability and reduce errors with explicit, self-documenting named arguments.
- **Coroutines**: Simplify asynchronous workflows with high-level coroutine abstractions.
- **Modules**: Replace traditional `#include` directives with efficient and modular code organization.

*Note*: Advanced features are detailed in the documentation but are not yet fully implemented in C++.

---

## Table of Contents

- [Getting Started](#getting-started)
- [Documentation](#documentation)
  - [Syntax Guide](docs/syntax.md)
  - [Grammar Specification](docs/grammar.md)
  - [Implementation Details](docs/implementation.md)
  - [Roadmap](docs/roadmap.md)
  - [Tour of C++Safe](docs/tour.md)
- [Examples](#examples)

---

## Getting Started

To explore C++Safe and see it in action:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/C++Safe.git
   cd C++Safe
   ```

2. **Build the Project**:
   Follow the instructions in [docs/implementation.md](docs/implementation.md) to set up and build C++Safe features within your environment.

3. **Run an Example**:
   Browse through [examples/ReadME.md](examples/ReadME.md) for runnable code examples demonstrating key features of C++Safe.

---

## Documentation

Explore the detailed guides and references for C++Safe:

- **[Tour of C++Safe](docs/tour.md)**: A guided overview of the language and its key features, including advanced functionality.
- **[Syntax Guide](docs/syntax.md)**: Comprehensive guide to the syntax improvements and enhancements in C++Safe.
- **[Grammar Specification](docs/grammar.md)**: Formal definition of the language's syntax using EBNF.
- **[Implementation Details](docs/implementation.md)**: Technical details on how C++Safe features are implemented using the C++ ecosystem, including Part 2 advanced features that are conceptually detailed but not yet implemented.
- **[Roadmap](docs/roadmap.md)**: Planned features and future enhancements.

---

## Examples

The `examples` folder contains C++ files showcasing the features of **C++Safe**. Each file is a runnable program demonstrating a specific feature, such as:

### Core Features:
- **Program Structure**: Simplified function declarations.
- **Statements**: Concise variable and constant declarations.
- **Expressions**: Streamlined output with `print`.
- **Functions**: Cleaner function definitions with `func` and `ret`.
- **Control Flow**: Enhanced loop syntax.
- **Memory Safety**: Automatic memory management with `safe`.
- **Concurrency**: Simplified asynchronous programming with `async_task` and `spawn`.
- **Slicing and Ranges**: Data manipulation with Python-like slicing and custom ranges.
- **Inline Testing**: Lightweight tests with `test` and `assert`.

### How to Compile and Run

1. Navigate to the `examples` folder:
   ```bash
   cd examples
   ```

2. Compile a file using `g++`:
   ```bash
   g++ -o <output_name> <file_name>.cpp
   ```

3. Run the compiled program:
   ```bash
   ./<output_name>
   ```

For more details, check out the [examples/ReadME.md](examples/ReadME.md).

---
