#include <iostream>           // pre-preoceesor direcitve
#include<vector>
using namespace std;

int average(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    return sum / n;
}

void printArray(int n)
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << arr[i];
    }
}

void minMaxOfArray(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "min : " << min << " max : " << max;
}

void reverseArray(int arr[], int n)
{
    // printing array in reverse
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }
    int arr2[n];
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
    cout << "reverse array";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int largestInArray(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int secondLargestInArray(int arr[], int n)
{
    int max1 = arr[0];
    int max2 = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] < max1 && arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    return max2;
}

void rotateArrayToLeft(int arr[], int n)
{
    // cout << "before";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
    // cout << "after";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}

void rotateArrayKTimes(int arr[],int n,int k){
    k = k % n;
    for (int i = 0; i < k;i++){
        // rotateArrayToLeft(arr,n);
        // version 2
        if(i +k < n )
        arr[i+k] = arr[i];
    }
}

int main()
{
    // int avg = average(5);
    // cout << "avg" << avg;

    // int n;
    // cin >> n;
    // printArray(n);
    int arr[] = {2, 4, 8, 5, 1};
    int n = 5;

    //  minMaxOfArray(arr,n);
    // reverseArray(arr,n);
    // cout << largestInArray(arr,n);
    // cout << secondLargestInArray(arr,n);
    // rotateArrayToLeft(arr, n);
        int k = 2;

    rotateArrayKTimes(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}