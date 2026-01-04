#include<iostream>
#include<string>
using namespace std;

int longestOddEvenSubsequence(int arr[], int n){
    
    int last_even_odd = arr[0] % 2;
    int count = 1;

    for(int i = 1;i<n;i++){
        int current_even_odd = arr[i] % 2;
        if(current_even_odd != last_even_odd){
            count++;
            last_even_odd = current_even_odd;
        }
    }
    
    return count;
}

void findDuplicateAndMissing(int arr[],int n){
    
    long long S  = n * (n +1) /2;
    long long S2 = n * (n +1) * (2*n +1) /6;

    long long SA =0, SA2 =0;
    for (int i=0;i<n;i++) {
        SA += arr[i];
        SA2 += arr[i] * arr[i];
    }

    long long diff1 = SA - S;// A - B
    long long diff2 = SA2 - S2;// A^2 - B^2

    long long sumAB = diff2 / diff1;// A + B

    long long A = (diff1 + sumAB) /2;
    long long B = A - diff1;

    cout << "A : " << A << " B : " << B ;
}

void rotateString(string &str,int k){
    int n = str.length();
    k = k % n;
    if (k == 0) return;
    string rotated = str.substr(k) + str.substr(0,k);
    str = rotated;
}

int main(){
    int arr[] = {5, 10, 5, 2, 1, 4};
    // int res = longestOddEvenSubsequence(arr,6);
    int arr2[]= {3 ,1 ,2 ,5 ,3};
    // findDuplicateAndMissing(arr2,5);

    // cout << "res " << res << endl;
    string str = "Sadik";
    rotateString(str,4);
    cout << "str " << str << endl;
    return 0;
}