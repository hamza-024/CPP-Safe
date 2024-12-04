#include <iostream>

// Macros 
#define func auto
#define ret return

// Example Functions
func add(int a, int b) -> int {
    ret a + b;
}

func greet() -> void {
    std::cout << "Hello from C++Safe!" << std::endl;
}

func multiply(int a, int b) -> int {
    ret a * b;
}

// Example Program
int main() {

    std::cout << "Addition (3 + 5): " << add(3, 5) << std::endl;
    greet();
    std::cout << "Multiplication (4 * 7): " << multiply(4, 7) << std::endl;

    return 0;
}
