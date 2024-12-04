#include <iostream>
#include <sstream>

// Macros
#define let auto
#define print(...) (std::cout << format(__VA_ARGS__) << std::endl)

// Helper function 
template <typename... Args>
std::string format(Args... args) {
    std::ostringstream oss;
    (oss << ... << args);  
    return oss.str();
}

// Example Program
int main() {

    let name = "C++Safe";

    print("Hello, World!");
    print("The sum of 3 and 5 is: ", 3 + 5);
    print("Value of pi: ", 3.14159);
    print("Welcome to ", name, "!");

    return 0;
}
