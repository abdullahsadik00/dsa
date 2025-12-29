#include <iostream>
using namespace std;

void printNumbersFrom1ToN(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
    }
    cout << endl;
}

void printEvenNumbersFrom1ToN(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            cout << i << endl;
        }
    }
    cout << endl;
}

void printNumbersFrom1ToNModulo100(int n) {

    // print all even numbers b/w N and M
    // input N, M from the user

    /*
    // IMPURE VERSION -> because this destroys the value of N
    int N, M; // 5, 10
    cin >> N >> M;
    cout << N << " " << M << endl; // 5 10

    for (; N <= M; N++) {
        cout << N << endl;
    }

    cout << N << " " << M << endl; // 11 10
    */

    /*
    int N, M; // 5, 10
    cin >> N >> M;
    cout << N << " " << M << endl; // 5 10

    for (int i = N; i <= M; i++) {
        if (i % 2 == 0)
            cout << i << endl;
    }

    cout << N << " " << M << endl; // 5 10
    */

    // Write a program to print
    // 1, 101, 201, 301, 401, 501, ... 1001
    // Time Complexity
    // assuming that every statemnt takes a constant amount of time to execute
    // small number * 1 ns << 1s
    // number of iterations our loop makes

    /*
    int count = 0;

    for (int i = 1; i <= 1001; i += 1) {
        count++;
        if (i % 100 == 1) {
            cout << i << endl;
        }
    }

    cout << count << endl; // try to avoid variable names that look like keywords or function names
    */

    // iterations = 1001

    // ------------------------

    /*
    int count2 = 0;

    for (int i = 1; i <= 1001; i += 100) {
        count2++;
        cout << i << endl;
    }

    cout << count2 << endl; // iterations = 11
    */

    int count = 0;
    for (int i = 1; i <= n; i++) {
        count++;
        if (i % 100 == 0) {
            cout << i << endl;
        }
    }
    cout << "count " << count << endl;

    int count2 = 0;
    for (int i = 1; i < n; i += 100) {
        count2++;
        cout << i << endl;
    }
    cout << "count2 " << count2 << endl;
}

void printNumbers2ToThePowerN(int n) {

    // Print all the powers of 2 from 2^0 .. 2^20

    /*
    int value = 1;
    for (int power = 0; power <= 20; power++) {
        cout << "2^" << power << " = " << value << endl;
        value = value * 2;
    }
    */

    // 2 4 8 16 ..
    // 1 2 4 8 ..
    // how many iterations = 21

    for (int i = 1; i <= n; i++) {
        cout << (1 << i) << endl; // 2^i is equivalent to 1 shifted left by i positions
    }
    cout << endl;
}

int main() {

    int N;
    cout << "Enter a number: ";
    cin >> N;

    // printNumbersFrom1ToN(N);
    // printEvenNumbersFrom1ToN(N);
    // printNumbersFrom1ToNModulo100(N);
    printNumbers2ToThePowerN(N);

  // Write a program to add all natural numbers uptil N
    // N = 10, 1 + 2 + 3 .. 9 + 10 = 55
    /*
    int total = 0;
    for(int i = 1; i <= N; i++) {
        total += i;
    }
    cout << total << endl;
    */
    // time complexity -> linear -> O(n)
    // can you change this program so that it becomes O(1)
    // need to rememeber the powers of 2 uptil 2^16
    // need to remember that 2^20 ~ 1million, 2^30 ~ 1 billion
    // formula for sum of first N natural numbers is n*(n+1) / 2
    // formula for sum of first N whole   numbers is n*(n-1) / 2 = sum of first N-1 natural numbers
    // formula for sun of squares of first N natural numbers
    // 1^2 + 2^2 + 3^2 .. N^2 = [n(n+1)/2] (2n+1)/3  = n(n+1)(2n+1)/6
    // formula for sun of cubes of first N natural numbers
    // 1^3 + 2^3 .. N^3 = (1 + 2 + ..N)^2 = (n(n+1)/2)^2
    // 1 + r + r^2 + r^3 .. r^m // Geometric Progression

    // O(1) is best
    // smaller is better
    // O(1) < O(log n) < O(n) < O(nlogn) < O(n^2) < O(n^2 log n) < O(n^3)
    // < O(2^n) < O(3^n) < O(n!) < O(n^n)
    //              O(n)
    // O(n log n) = O(n) * O(log n)
    // O(n^2)     = O(n) * O(n)

    // print the factorial of N
    // n! = 1 * 2 * 3 .. n
    int factorial = 1;
    for(int i = 1; i<= N; i++) {
        factorial *= i;
    }
    cout << factorial << endl;
    // must remember factorials uptil 6
    /*
    0! = 1
    1! = 1
    2! = 2
    3! = 6
    4! = 24
    5! = 120
    6! = 720
    */

    // why do you initialize with 0 when using +
    // why do you initialize with 1 when using *
    //                                         (op)
    // it is because 0 + x = x, 1 * x = x
    // identity of +, is 0
    // identity of *, is 1
    // x op id = x
    // why do you initialize with infinity when using min
    // identity of min?
    // min(x, infinity) = x

    // min of all numbers from 1 till N
    // 1
    // infinity is NotANumber NaN
    // infinity, INT_MAX, max possible value in the range, pick any number from the input
    // int min = 1; // initialized with identity of min
    // for(int i = 1; i <= N; i++) {
    //     min = minimum(min, i);
    // }
    // cout << min << endl;

    for(int i = 1; i < N; i++) {
        cout << i << endl;
    } 
    
    // N iterations => complexity is O(N)
    // N = 10,000
    // 1, 2, 3, 4, 5, 6 ... 1000, 1001, .. 9998, 9999
    // ----------- 10,000 steps ---------------------

    for(int i = 1; i < N; i += 2) {
        cout << i << endl;
    } // N/2 iterations   => O(N)
    // 1, 3, 5, 7, 9 .. N
    
    for(int i = 1; i < N; i += 100) {
        cout << i << endl;
    } // N/100 iterations  => O(N)
    // 1, 101, 201, 301, .. 
    // N = 10,000
    // 1, 101, 201, 301, ... 9001, ... 9901
    // -------------- 100 steps -----------

    // O(a*N + b) => O(N)
    // a > 0, a & b are a constant
    // if N becomes 10 times, then how does my number of steps change

    for(int value = 1; value < N; value *= 2) {
        cout << value << endl;
    }
    // 1st iteration -> value = 1 = 2^0
    // 2nd iteration -> value = 2 = 2^1
    // 3rd iteration -> value = 4 = 2^2
    // kth iteration -> value =   = 2^k
    // the moment 2^k > N we will come out of the loop
    // 2^k > N   (find the value of k, such that this is true)
    // log_2(2^k) > log_2(N)
    // k * log_2(2) > log_2(N)
    // k > log_2(N)
    // k = log_2(N) + 1
    // k = O(log_2 N)

    return 0;
}