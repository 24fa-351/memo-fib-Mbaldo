#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to calculate the Nth Fibonacci number
long long int fibonacci_recursive(long long int n) {
    if (n == 1) {
        return 0;  // Start the sequence with fib(1) = 0
    }
    if (n == 2) {
        return 1;  // The second Fibonacci number is 1
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function to calculate the Nth Fibonacci number
long long int fibonacci_iterative(long long int n) {
    if (n == 1) {
        return 0;  // Start the sequence with fib(1) = 0
    }
    if (n == 2) {
        return 1;  // The second Fibonacci number is 1
    }
    long long int a = 0, b = 1, fib = 0;
    for (long long int i = 3; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    // Parse the first argument (an integer)
    long long int input_num = atoll(argv[1]);

    // Parse the second argument (method: r or i)
    char method = argv[2][0];

    // Calculate the Nth Fibonacci number based on the method
    long long int result;
    if (method == 'r') {
        result = fibonacci_recursive(input_num);
    } else if (method == 'i') {
        result = fibonacci_iterative(input_num);
    } else {
        return 1;
    }

    // Output only the result
    printf("%lld\n", result);

    return 0;
}
