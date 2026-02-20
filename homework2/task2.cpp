#include <iostream>
#include <vector>

int fibMemo(int a, std::vector<int>& memo) {
    if (a < 1) {
        return 0;
    }
    if (a == 1 || a == 2) {
        return 1;
    }

    if (memo[a] != -1) {
        return memo[a];
    }

    memo[a] = fibMemo(a - 1, memo) + fibMemo(a - 2, memo);
    return memo[a];
}

int fib(int a) {
    if (a < 1) {
        return 0;
    }

    std::vector<int> memo(a + 1, -1);

    memo[1] = memo[2] = 1;

    return fibMemo(a, memo);
}

int main() {
    std::cout << fib(10) << std::endl;
    std::cout << fib(45) << std::endl;

    return 0;
}