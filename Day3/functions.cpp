#include <iostream>

using namespace std;

void swap1(int & , int &); // function declaration
// pass by value
// pass by reference

// scope , global , local 

void swap1(int & x , int & y) {

  int temp = x;
  x = y;
  y = temp;
}


// why main() is int only ? 
// Becuase main() is expected to return int only , as we need to send the exit codes
int main() {
  // operating system
  // _start : main
  // nCr = n! / (r!) * (n - r)!
  // long , long long int 
  // type , order, number 
  // function declaration
  int x= 10;
  int y = 5;
  swap1(x , y);
  cout << x << " " << y << endl;
  // code is succefully run

  // 0-255 codes
  // segmentation fault - 139
  // time limit exceeded - 158
  cin >> x;
  while(x > 0){
    cout << x << endl;
    cin >> x;
  }
  return 0; // 0 here is representing success - exit code for success
}