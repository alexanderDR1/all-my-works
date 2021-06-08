#include <iostream>
#include <chrono>
#include <random>

struct hi {
    int a;
    char b;
    double c;
};

int main() {
    std::cout << sizeof(hi) << std::endl;

    int s = 640000;
    int *myarr = new int[s];

    // 1-Step Linear memory access
    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i < s; i++) {
        myarr[i] = 100;
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;

    // n-Step Linear memory access
    start = std::chrono::steady_clock::now();
    for(int i = 0; i < s * 33; i += 33) {
        myarr[i % s] = 100;
    }
    end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;

    // Random memory access
    start = std::chrono::steady_clock::now();
    for(int i = 0; i < s; i++) {
        myarr[rand() % s] = 100;
    }
    end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;
    return 0;
}
