#include <iostream>

using namespace std;

template<int N, int D = N - 1>
struct isPrime {
    enum {
        result = (N % D) && isPrime<N, D - 1>::result
    };
};
template<int N>
struct isPrime<N, 1> {
    enum {
        result = true
    };
};

template<int N, bool ISPRIME>
struct printIfPrime {
    static void inline print() {}
};
template<int N>
struct printIfPrime<N, true> {
    static void inline print() {
        cout << N << endl;
    }
};

template<int N, int MAX>
struct printPrime {
    static void inline print() {
        printIfPrime<N, isPrime<N>::result>::print();
        printPrime<N + 1, MAX>::print();
    }
};
template<int N>
struct printPrime<N, N> {
    static void inline print() {
        printIfPrime<N, isPrime<N>::result>::print();
    }
};

int main() {
    printPrime<2, 40>::print();
    return 0;
}
