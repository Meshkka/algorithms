#include <iostream>

int fib(int a) {
    if ((a == 1) || (a == 2)) {
        return 1;
    }
    else if (a < 1) {
        return 0;
    }
    else {
        return fib(a - 1) + fib(a - 2);
    }
}

int main()
{
    std::cout << fib(10);

    return 0;
}

// так как чтобы вычислить каждое следующее число мы должны складывать 2 предыдущих,
// объЄм вычислений удваиваетс€ на каждом шаге, значит врем€ будет ќ(2^n)