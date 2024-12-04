#include <iostream>
#include <memory>
#include <vector> 

// Macro
#define safe(type, ...) std::make_shared<type>(__VA_ARGS__)

// Example Program
int main() {
    // Safe Pointer 
    auto ptr = safe(int, 42);
    std::cout << "Value in safe pointer: " << *ptr << std::endl;

    auto arr = safe(std::vector<int>, std::initializer_list<int>{1, 2, 3, 4, 5});
    std::cout << "Array elements in safe pointer: ";
    for (const auto& num : *arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
