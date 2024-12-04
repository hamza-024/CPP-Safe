#include <iostream>
#include <thread>
#include <future>

// Macros 
#define async_task std::async
#define await std::future
#define spawn(block) std::thread([]() { block; })

// Example Task for Async
int fetchData() {
    std::cout << "Fetching data asynchronously..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    return 42;
}

// Example Program
int main() {
    // Async Example
    auto result = async_task(std::launch::async, fetchData);
    std::cout << "Result from async task: " << result.get() << std::endl;

    // Thread Example
    spawn({
        std::cout << "Running in a separate thread!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Thread completed!" << std::endl;
    }).join(); // Wait for thread to finish

    return 0;
}
