#include <iostream>
using namespace std; // to write less code

int main()
{
    /*
        int a; // declaration of a variable

        // I want a variable of type "int" with the name "a"
        // int -> datatype
        // a   -> variable name
        // int stores integers
        // int can store:
        //   - negative integers
        //   - zero
        //   - positive integers
        //
        // int usually takes 4 bytes of memory
        // 4 bytes = 32 bits
        //
        // Example (binary):
        // 00000000000000000000000000000111
        //
        // Each bit can be either 0 or 1
        // Total combinations = 2^32
        //
        // Range of int:
        // -2^31            to            2^31 - 1
        // -2147483648                     2147483647

        cout << sizeof(int) << endl; // size of int (usually 4 bytes)

        cout << a << endl; // uninitialized variable (contains garbage value)

        long int b;
        cout << sizeof(long) << endl; // usually 8 bytes on 64-bit systems

        // Range of long (typically):
        // -2^63            to            2^63 - 1

        a = 2147483647;
        cout << a << endl;

        // Datatypes are signed by default
        // Signed integers can store:
        //   - negative values
        //   - zero
        //   - positive values
        //
        // Unsigned integers:
        //   - store only non-negative values
        //   - unsigned int range: 0 to 2^32 - 1
        //   - unsigned long range: 0 to 2^64 - 1

        cout << sizeof(unsigned int) << endl;       // 32-bit unsigned int
        cout << sizeof(unsigned long) << endl;      // 64-bit unsigned long
        cout << sizeof(unsigned long long) << endl; // 64-bit unsigned long long

        // 64-bit machine:
        // int        -> 32 bit
        // long long -> 64 bit
        //
        // 32-bit machine:
        // int        -> 16 bit
        // long       -> 32 bit
        // long long -> 64 bit

        int x = 7.5;   // fractional part ignored
        int y = -7.5;  // -7

        /*
            floor(x) -> largest integer less than x
            floor(7.5)  = 7
            floor(-7.5) = -8 

        cout << "x : " << x << "  y : " << y << endl;
        */

        // Floating point numbers
        float  f1 = 1.23456789;        // 4 bytes
        double d  = 1.2345678901234;   // 8 bytes

        cout << sizeof(f1) << endl;
        cout << sizeof(d) << endl;
        cout << f1 << endl; // precision ~6–7 digits
        cout << d << endl;  // precision ~15–16 digits

        bool flag = true; // usually 1 byte
        cout << sizeof(flag) << endl;
        cout << flag << endl; // prints 1 for true, 0 for false

        // Character type
        char ch = 'A';
        cout << sizeof(ch) << endl;
        cout << ch << endl;

        char vtab = '\v'; // vertical tab
        cout << "Hello" << endl;
        cout << vtab << endl;
        cout << "World" << endl;

        char ascii = 65; // ASCII of 'A'
        cout << ascii << endl;

        string str = "Hello, World!";
        cout << str << endl;

        // Primitive: int, float, double, char, bool
        // Compound: string, arrays, struct, vector

        int e = 10;
        int f = 20;
        int g;

        g = e + f;
        g = e - f;
        g = e * f;
        g = e / f;
        g = e % f;

        cout << "g : " << g << endl;

        float h = 5.5;
        float i = 10.5;
        float j;

        j = h + i;
        j = h - i;
        j = h * i;
        j = h / i;

        cout << "j : " << j << endl;

        // Type casting
        int p = 7;
        int q = 89;

        cout << "p / q : " << p / q << endl;              // integer division
        cout << "p / q : " << float(p) / q << endl;
        cout << "p / q : " << p / float(q) << endl;
        cout << "p / q : " << float(p) / float(q) << endl;
        cout << "p / q : " << float(p / q) << endl;       // still 0

    /*
        2's complement explanation:

        2's complement of a number =
        1's complement (invert bits) + 1

        Example:
        2  = 00000010
        ~2 = 11111101
        +1 = 11111110
    */

    return 0; // boilerplate
}