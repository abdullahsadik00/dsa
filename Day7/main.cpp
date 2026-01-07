#include <iostream>
#include <vector>
using namespace std;

// Rotate a 1D array to the left by k positions
vector<int> leftRotate(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return {};
    k = k % n;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[(i + n - k) % n] = arr[i];
    }
    return result;
}
// Example:
// vector<int> arr = {1,2,3,4,5};
// leftRotate(arr,2) => {3,4,5,1,2}

void twodArray() {
    int n = 5, m = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (i + 1) * (j + 1) << " ";
        }
        cout << endl;
    }
}
// Output:
// 1 2 3 4
// 2 4 6 8
// 3 6 9 12
// 4 8 12 16
// 5 10 15 20

void inversionCount(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                cout << "[ " << i << "," << j << " ]" << endl;
            }
        }
    }
}
// Example:
// arr = {2,3,1}
// Output:
// [0,2]
// [1,2]

void rightToLeft() {
    int n = 4, m = 3;
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            cout << i << j << " ";
        }
        cout << endl;
    }
}
// Output:
// 02 01 00
// 12 11 10
// 22 21 20
// 32 31 30

void scalerMultiplication(vector<vector<int>>& arr, int b) {
    int row = arr.size();
    int col = arr[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] *= b;
        }
    }
}
// Example:
// arr = {{1,2},{3,4}}, b = 2
// arr after function => {{2,4},{6,8}}

void addMatrix(vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    int row = arr1.size();
    int col = arr1[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr1[i][j] += arr2[i][j];
        }
    }
}
// Example:
// arr1 = {{1,2},{3,4}}, arr2={{5,6},{7,8}}
// arr1 after function => {{6,8},{10,12}}

bool isMatrixSame(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    int row = arr1.size();
    int col = arr1[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr1[i][j] != arr2[i][j]) 
                return false;
        }
    }
    return true;
}
// Example:
// arr1={{1,2},{3,4}}, arr2={{1,2},{3,4}} => true
// arr1={{1,2},{3,4}}, arr2={{1,2},{4,3}} => false

vector<vector<int>> transposeMatrix(const vector<vector<int>>& arr) {
    if (arr.empty()) return {};
    int rows = arr.size();
    int cols = arr[0].size();
    vector<vector<int>> res(cols, vector<int>(rows));
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            res[i][j] = arr[j][i];
        }
    }
    return res;
}
// Example:
// arr={{1,2,3},{4,5,6}}
// transposeMatrix(arr) => {{1,4},{2,5},{3,6}}

int main() {
    // 1D array rotation example
    vector<int> arr = {2, 3, 1, 6, 7, 5};
    vector<int> rotated = leftRotate(arr, 2);
    cout << "Left rotated array: ";
    for (int x : rotated) cout << x << " ";
    cout << "\n\n";

    // Scalar multiplication example
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };
    scalerMultiplication(matrix, 2);
    cout << "Matrix after scalar multiplication:\n";
    for (auto row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "\n";

    // Matrix addition example
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    addMatrix(A, B);
    cout << "Matrix after addition:\n";
    for (auto row : A) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    // Transpose example
    vector<vector<int>> T = transposeMatrix(A);
    cout << "\nTranspose of matrix:\n";
    for (auto row : T) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}