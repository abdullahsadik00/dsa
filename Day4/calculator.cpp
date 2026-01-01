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
    switch (choice)
    {
    case 1:
        cout << "Addition Selected" << endl;
        cout << "Enter two numbers to add: ";
        int a, b;
        cin >> a >> b;
        cout << a << " + " << b << "=" << (a + b) << endl;
        break;
    case 2:
        cout << "Subtraction Selected" << endl;
        break;
    case 3:
        cout << "Multiplication Selected" << endl;
        break;
    case 4:
        cout << "Division Selected" << endl;
        break;
    case 5:
        cout << "Factorial Selected" << endl;
        break;
    case 6:
        cout << "No. of Zeros at the end of Factorial Selected" << endl;
        break;
    case 7:
        cout << "Zen Mode Selected" << endl;
        break;
    default:
        cout << "Exiting Calculator. Goodbye!" << endl;
    }

    return 0;
}