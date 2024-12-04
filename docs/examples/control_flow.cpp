#include <iostream>
#include <vector>

// Macro 
#define for_in(var, range) for (auto var : range)

// Example Program
int main() {
    // For Loop Example with range-based iteration
    std::vector<int> nums = {1, 2, 3, 4, 5};
    for_in(num, nums) {
        std::cout << "Number: " << num << std::endl;
    }

    return 0;
}
