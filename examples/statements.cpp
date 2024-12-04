#include <iostream>

// Macros 
#define let auto
#define const_ const auto

// Example Program
int main() {

    let x = 42;
    let name = "C++Safe";

    const_ pi = 3.14159;

    std::cout << "Variable x: " << x << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Constant pi: " << pi << std::endl;

    return 0;
}
