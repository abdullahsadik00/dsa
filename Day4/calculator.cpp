#include <iostream>
using namespace std;

int main()
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
        int fact = 1;
        for (int i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        cout << "Factorial of " << n << " is " << fact << endl;
    }
    else if (choice == 6)
    {
        int n;
        cout << "Enter a number:";
        int numberOfZeros = 0;
        cin >> n;
        while (n > 0)
        {
            numberOfZeros += n / 5;
            n /= 5;
        }
        cout << "Number of trailing zeros in factorial is " << numberOfZeros << endl;
    }

    return 0;
}