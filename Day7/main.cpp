#include<iostream>
#include<vector>
using namespace std;

vector<int> leftRotate(vector<int> arr,int k){
    int n = arr.size();
    k = k % n;
    vector<int> finalArray(n);
    for(int i = 0;i<n;i++){
        finalArray[(i + n-k)%n] = arr[i];
    }
    return finalArray;
}

void inversionCount(vector<int> arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        for (int j = i+1;j<n;j++){
            if(arr[i] > arr[j]){
                cout << "[ "<< i << "," << j <<"]" << endl;
            }
        }
    }
}

int main() {
    vector<int> arr = {2,3,1,6,7,5};
    
    vector<int> result = leftRotate(arr, 6);

    // for (int x : result) {
    //     cout << x << " ";
    // }

    inversionCount(arr);
    return 0;
}