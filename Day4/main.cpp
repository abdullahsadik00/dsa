#include<iostream>
using namespace std;


int gcd(int a, int b){
    int min = 0;
    int max = 0;
    if (a < b){
        min = a;
        max = b;
    }
    else{
        min = b;
        max = a;
    }
        int ans = 0;
    for (int i = 1; i * i <= min; i++){
        if ((a % i == 0) && (b % i == 0)){
            ans = i;
        }
        if (a % (min / i) == 0 && b % (min / i) == 0) {
        ans = min/i;
        break;
        }

    }
    return ans;
}

int main(){

    cout << gcd(100,250);
    return 0;
}