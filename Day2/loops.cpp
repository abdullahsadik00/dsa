#include <iostream>
using namespace std;

void printFactorsOfN(int n) {
    // Version 1: Simple Approach
    int count = 0;
    // Loop from 1 to n to check for factors
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { // Check if i divides n completely
            count++; // Increment count for every factor found
        }
    }
    cout << "Number of factors: " << count << endl;
    cout << "-----------------" << endl;

    // Version 2: Optimized Approach
    int count2 = 1; // 1 is always a factor of any number
    // Loop from 1 to n/2 instead of n
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) { // Check if i divides n completely
            count2++; // Increment count for every factor found
        }
    }
    cout << "Number of factors (Version 2): " << count2 << endl;

    // Version 3: Advanced Optimization (Using Square Root)
    int count3 = 0;
    // Loop from 1 to the square root of n
    // We only need to loop up to sqrt(n) because factors come in pairs.
    // For example, if n = 36, (1, 36), (2, 18), (3, 12), (4, 9), (6, 6)
    // After reaching sqrt(n), we have already counted all factor pairs.
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) { 
            count3++; // i is a factor (pair 1)
            if (i != n / i) { 
                count3++; // n / i is a factor (pair 2), but don't count if it's the same as i
            }
        }
    }
    cout << "Number of factors (Version 3 - Optimized): " << count3 << endl;
}

bool isPrime(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++; // for i (because factor is in pair)
            if (i != n / i) {
                count++; // because if the numbers are the same, we should not count twice
            }
        }
    }
    return count == 2; // A prime number has exactly 2 divisors: 1 and the number itself
}

void printPatterns(int n) {
    // Pattern 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j; // cout << "* ";
        }
        cout << endl;
    }
    cout << "------------------" << endl;

    // Pattern 2
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j; // cout << "* ";
        }
        cout << endl;
    }

    cout << "------------------" << endl;

    // Pattern 3
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << j;
        }
        cout << endl;
    }

    cout << "------------------" << endl;

    // Pattern 4
    for (int i = 1; i <= 2 * n; i++) {
        if (i <= n) {
            for (int j = 1; j <= n - i + 1; j++) {
                cout << j;
            }
            cout << endl;
        } else {
            for (int j = 1; j <= i - n; j++) {
                cout << j;
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Uncomment the line below to test the factors function
    // printFactorsOfN(n);

    // Uncomment the logic below to test prime numbers
    // for (int i = 1; i <= n; i++) {
    //     if (isPrime(i)) {
    //         cout << i << " is a prime number" << endl;
    //     }
    // }

    // Call printPatterns to print the patterns based on n
    printPatterns(n);
    return 0;
}
