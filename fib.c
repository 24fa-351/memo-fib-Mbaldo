#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIB 100 // Define a limit for memoization

// Global array for memoization
long long int memo[MAX_FIB];

// Recursive Fibonacci function with memoization applied
long long int fib_r(long long int n) {
    if (n <= 1) {
        return n;
    }
    
    // If the value has already been computed, return it from memo
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Otherwise, compute it recursively and store it in memo
    memo[n] = fib_r(n - 1) + fib_r(n - 2);
    return memo[n];
}

// Iterative Fibonacci function (no need for memoization, but included for consistency)
long long int fib_i(long long int n) {
    if (n <= 1) {
        return n;
    }
    long long int a = 0, b = 1, fib = 0;
    for (long long int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 1;
    }

    // Parse the first argument (an integer)
    long long int input_num = atoll(argv[1]);

    // Parse the second argument (method: r or i)
    char method = argv[2][0];

    // Parse the third argument (filename)
    FILE *file = fopen(argv[3], "r");
    if (!file) {
        return 1;
    }

    // Read the integer from the file
    long long int file_num;
    fscanf(file, "%lld", &file_num);
    fclose(file);

    // Add the two integers
    long long int N = input_num + file_num;

    // Initialize memoization array with -1
    for (int i = 0; i <= N; i++) {
        memo[i] = -1;
    }

    // Calculate the Nth Fibonacci number based on the method
    long long int result;
    if (method == 'r') {
        result = fib_r(N);
    } else if (method == 'i') {
        result = fib_i(N);
    } else {
        return 1;
    }

    // Output only the result
    printf("%lld\n", result);

    return 0;
}
