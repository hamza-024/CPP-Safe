#include <iostream>
#include <vector>

// Slicing Function 
template <typename T>
std::vector<T> slice(const std::vector<T>& vec, size_t start, size_t end) {
    if (start >= vec.size() || end > vec.size() || start >= end) {
        throw std::out_of_range("Invalid slice indices");
    }
    return {vec.begin() + start, vec.begin() + end};
}

// Macro
#define range(start, end, step) [](int s, int e, int st) {        \
    std::vector<int> r;                                           \
    for (int i = s; i < e; i += st) r.push_back(i);               \
    return r;                                                     \
}(start, end, step)

// Example Program
int main() {
    // Slicing Example
    std::vector<int> nums = {10, 20, 30, 40, 50};
    try {
        auto subArray = slice(nums, 1, 4);  // Extract elements from index 1 to 3
        std::cout << "Sliced Array: ";
        for (const auto& num : subArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Ranges Example
    std::cout << "Range-based Loop: ";
    for (const auto& i : range(0, 10, 2)) {  // Start, end, step
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
