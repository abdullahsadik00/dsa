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

    cout << sizeof(unsigned int) << endl;  // size of 32 bit unsigned int
    cout << sizeof(unsigned long) << endl; // size of 64 bit unsigned long

    cout << sizeof(unsigned long long) << endl; // size of 64 bit unsigned long long
    // 64 bit machine ->bus size, memory pointer is of 64 bit
    // int 32 bit
    // long long 64 bit
    // long long 64 bit

    // 32 bit machine -> bus size, memory pointer is of 32 bit  -> only support 4 GB RAM
    // int 16 bit
    // long 32 bit
    // long long 64 bit

    int x = 7.5;  // the fractional part will be ignored
    int y = -7.5; // -7
    /*
    floor (x) -> largest integer less than x
    floor (7.5) = 7
    floor(-7.5) = -8
    floor (0) = 0
    floor (1) = 1
    floor(-1) = -1
    floor (n) = n, where n is an integer
    -7 < -7.5? NO
    -8 < -7.5
    -9 < -7.5
    */
   /*
   cout << "x : " << x << " "<< "  y : " << y << endl;
    
   // floating point number -> both +ve and -ve fractions or integers
   float f1 = 1.23456789;       // usually 4 bytes
   double d = 1.2345678901234; // usually 8 bytes
   cout << sizeof(f1) << endl; // size of float -> rounding them off
   cout << sizeof(d) << endl; // size of double
   cout << f1 << endl;         // precision up to 6-7 digits
   cout << d << endl;         // precision up to 15-16 digits

   bool flag = true;  // 1 byte (usually)
   cout << sizeof(flag) << endl;
   cout << flag << endl; // prints 1 for true and 0 for false

   // bool is of 1 byte, and not 1 bit in size because
   // our memory is byte addressable

   char ch; // store any ASCII value
   cout << sizeof(ch) << endl; // size of char is 1 byte
   ch = 'A';
   cout << ch << endl; // prints A

   char vtab;
   vtab = '\v'; // vertical tab -> non-printable character
   cout << "Hello" << endl;
   cout << vtab << endl;
   cout << "World" << endl;

   char ascii;
   ascii = 65; // ASCII value of 'A' is 65
   cout << ascii << endl; // prints A

   // for (int i = 0; i < 256; i++)
   // {
   //     cout << i << " : " << char(i) << endl;
   // }
   
   string str = "Hello, World!"; 
   cout << str << endl;

   // string datatype is not a primitive datatype (Compount datatype)
   // int, float, double, char, bool are primitive datatypes
   // string, arrays, struct, vector are compound datatypes

   int e = 10; // declaration + initialization
   int f = 20;

   int g;
   g = e + f; // assignment
   g = e - f;
   g = e * f;
   g = e / f;
   g = e % f; // modulus operator
   cout << 'g : ' << g << endl;

   float h = 5.5;
   float i = 10.5;
   float j;
   j = h + i;
   j = h - i;
   j = h * i;
   j = h / i;
   // j = h % i;  invalid -> modulus operator not defined for float it will only work for integers
   cout << "j : " << j << endl;    

   // Implicit type casting
   int p = 7;
   int q = 89;
   // int / int -> int
   // int / float -> float
   // float / int -> float
   // float / float -> float
   cout << "p / q : " << p / q << endl; // 0.0786517

   // Explicit type casting
   cout << "p / q : " << float(p) / q << endl; // 0.0786517
   cout << "p / q : " << p / float(q) << endl; // 0.0786517
   cout << "p / q : " << float(p) / float(q) << endl; // 0.0786517 
   cout << "p / q : " << float (p / q) << endl; // 0
   
    */

    /*
         10 => 1010 (binary)
        -10 => abcd
        -----------
          0 => 0000
    
               11          
         10 => 1010 (binary)
        -10 => 0110
        -----------
          0 => 0000
          
              S|----
          6 =>  0110 (binary)
        -10 =>  0110

Interger are 8 bits in size
        
        S|1234567
        -2 => 1|0000010    
        -1 => 1|0000001
        0  => 0|0000000
        1  => 0|0000001
        2  => 0|0000010
        3  => 0|0000011
        4  => 0|0000100
        
        -1 => 1|0000001
         1 => 0|0000001
        ===============
         0 => 1|0000010

            2's complement of a number = invert all bits + 1
            x => 1's complement of x + 1

             2 =>  0|0000 0010
               =>  1|1111 1101 (1's complement)
               =>            1 (+1)
               ========================
               =>  1|1111 1110
        

               computer has electric circuits
               and we've complex circuit for + for +ve numbers
               and if we want to do -ve number +  +ve number or
                -ve number + -ve number, we would need another complex circuit
               so instead of building another complex circuit,
               we use 2's complement representation of -ve numbers
               so that we can use the same +ve number addition circuit
               to add both +ve and -ve numbers
               
        
        */

    return 0; // boilerplate that we always have to write
}