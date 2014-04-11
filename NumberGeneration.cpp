#include <iostream>

template<int N>
struct NumberGeneration {
    static void inline print() {
        NumberGeneration<N - 1>::print();
        std::cout << N << std::endl;
    }
};
template<>
struct NumberGeneration<1> {
    static void inline print() {
        std::cout << 1 << std::endl;
    }
};

int main() {
    NumberGeneration<200>::print();
    return 0;
}
