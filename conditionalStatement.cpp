#include <iostream>
using namespace std;

void minimumOfTwoNumbers(int a, int b) {
    if (a < b) {
        cout << a << " is the minimum number." << endl;
    } else {
        cout << b << " is the minimum number." << endl;
    }
}

void maximumOfTwoNumbers(int a, int b) {
    if (a > b) {
        cout << a << " is the maximum number." << endl;
    } else {
        cout << b << " is the maximum number." << endl;
    }
}

int main() {
    // programing constructs
    // syntax -> representation of something
    // semantics -> meaning of something
    
    /*
    if (condition) {
        // code to be executed if condition is true
    } else {
        // code to be executed if condition is false
    }
    */

    // in C++ spaces are ignored
    // indentation is not necessary for code to run but it is necessary for code to be readable

    /*
    Blocks
    1. expressions -> always evaluate to a value
    2. statements -> exist on their own and do not evaluate to a value

        <---------> expression
    a = b + c * 10;
    <-------------> statement

    {
        statement1;
        statement2;
        ...
    } -> block statement

    whenever we have multiple statements to be executed together, we use block statements
    */

    /*
    truthy and falsy values
    In C++, the following values are considered falsy:
    1. The integer value 0
    2. The floating-point value 0.0
    3. The null pointer (nullptr)
    4. The boolean value false
    5. The character value '\0' (null character)
    All other values are considered truthy.
    */

    // if (10 + 20) {
    //     cout << "This condition is true" << endl;
    // } else {
    //     cout << "This condition is false" << endl;
    // }

    // if (10 / 10) {
    //     cout << "This condition is true" << endl;
    // } else {
    //     cout << "This condition is false" << endl;
    // }


    // Given the year determine whether it is a leap year or not

    // 1700 -> f || (f && t) -> f || f -> f -> not a leap year
    // 1600 -> t || (f && t) -> f || t -> t -> leap year
    // 2004 -> f || (t && t) -> f || t -> t -> leap year
    // 2003 -> f || (t && f) -> f || f -> f -> not a leap year
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    /*
    Boolean operators
    1. AND (&&) -> & is bitwise AND operator while && is logical AND operator
    2. OR (||) -> | is bitwise OR operator while || is logical OR operator
    3. NOT (!) -> ~ is bitwise NOT operator while ! is logical NOT operator
    4. XOR (^)
    5. NAND
    6. NOR
    7. XNOR

    Operator precedence
    1. NOT
    2. AND
    3. OR
    4. XOR
    5. NAND
    6. NOR
    7. XNOR
    8. Implication
    9. Biconditional
    10. Assignment
    11. Comma

    x  y    x && y    x || y    x ^ y
    ---------------------------------------
    0  0      0          0        1
    0  1      0          1        1
    1  0      0          1        0
    1  1      1          1        0
    ---------------------------------------
    
    */
    int firstNumber, secondNumber;
    cout << "Enter two numbers: ";
    cin >> firstNumber >> secondNumber;
    
    minimumOfTwoNumbers(firstNumber, secondNumber);
    maximumOfTwoNumbers(firstNumber, secondNumber);

    return 0;
}