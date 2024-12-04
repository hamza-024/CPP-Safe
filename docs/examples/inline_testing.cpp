#include <iostream>
#include <string>

// Macros 
#define test(desc, block)                          \
    do {                                           \
        std::cout << "Running test: " << desc      \
                  << std::endl;                    \
        block;                                     \
    } while (0)

#define assert(condition)                          \
    if (!(condition)) {                            \
        std::cerr << "Assertion failed: "          \
                  << #condition << std::endl;      \
    } else {                                       \
        std::cout << "Assertion passed: "          \
                  << #condition << std::endl;      \
    }

// Example Program
int add(int a, int b) {
    return a + b;
}

bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    // Inline Tests
    test("Addition Test", {
        assert(add(2, 3) == 5);
        assert(add(-1, 1) == 0);
    });

    test("Even Number Test", {
        assert(isEven(4) == true);
        assert(isEven(5) == false);
    });

    test("String Equality Test", {
        std::string hello = "Hello";
        std::string world = "World";
        assert(hello + " " + world == "Hello World");
    });

    return 0;
}
