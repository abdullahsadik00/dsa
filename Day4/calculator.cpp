#include <iostream>
using namespace std;

const int NORMAL_MODE = 0;
const int ZEN_MODE = 1;
const int EXIT = -1;

int factorialOfN(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }
    return fact;
}

int trailingZerosOfEnd(int n)
{
    int numberOfZeros = 0;
    while (n > 0)
    {
        numberOfZeros += n / 5;
        n /= 5;
    }
    return numberOfZeros;
}
int normalMode()
{
    cout << "\t1. Add two numbers" << endl;
    cout << "\t2. Subtract two numbers" << endl;
    cout << "\t3. Multiply two numbers" << endl;
    cout << "\t4. Divide two numbers" << endl;
    cout << "\t5. Factorial of a number" << endl;
    cout << "\t6. No. of Zeros at the end factorial" << endl;
    cout << "\t7. Enter Zen Mode" << endl;
    cout << "Enter Anything Else to Exit" << endl;

    int choice;
    cin >> choice;
    if (choice >= 1 && choice <= 4)
    {
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        switch (choice)
        {
        case 1:
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case 2:
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case 3:
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case 4:
            if (b != 0)
                cout << a << " / " << b << " = " << (a / b) << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        }
    }
    else if (choice == 5)
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        cout << "Factorial of " << n << " is " << factorialOfN(n) << endl;
    }
    else if (choice == 6)
    {
        int n;
        cout << "Enter a number:";
        cin >> n;
        cout << "Number of trailing zeros in factorial is " << trailingZerosOfEnd(n) << endl;
    }
    else if (choice == 7)
    {
        return ZEN_MODE;
    }
    else
    {
        return EXIT;
    }

    return NORMAL_MODE;
}

int zenMode()
{
    cout << "Welcome of zen mode" << endl;
    int a, b;
    string s;
    cin >> s;
    if (s == "normal")
    {
        return NORMAL_MODE;
    }
    else if (s == "exit")
    {
        return EXIT;
    }
    a = stoi(s);
    string arithmaticOperator;
    cin >> arithmaticOperator;
    if (arithmaticOperator == "+")
    {
        cin >> b;
        cout << (a + b) << endl;
    }
    else if (arithmaticOperator == "-")
    {
        cin >> b;
        cout << (a - b) << endl;
    }
    else if (arithmaticOperator == "*")
    {
        cin >> b;
        cout << (a * b) << endl;
    }
    else if (arithmaticOperator == "/")
    {
        cin >> b;
        cout << (a / b) << endl;
    }
    else if (arithmaticOperator == "!")
    {

        cout << "Factorial of " << a << " is " << factorialOfN(a) << endl;
    }
    else if (arithmaticOperator == "!!")
    {
        cout << "Number of trailing zeros in factorial is " << trailingZerosOfEnd(a) << endl;
    }

    return ZEN_MODE;
}
int main()
{

    int mode = 0;
    while (mode >= 0)
    {
        if (mode == NORMAL_MODE){
            mode = normalMode();
        }
        else if (mode == ZEN_MODE){
            mode = zenMode();
        }
    }

    return 0;
}