#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int min = 0;
    int max = 0;
    if (a < b)
    {
        min = a;
        max = b;
    }
    else
    {
        min = b;
        max = a;
    }
    int ans = 0;
    for (int i = 1; i * i <= min; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            ans = i;
        }
        if (a % (min / i) == 0 && b % (min / i) == 0)
        {
            ans = min / i;
            break;
        }
    }
    return ans;
}

string isArmstrongNumber(int n)
{
    int originalNo = n;
    int digits = 0;
    int sum = 0;
    while (n > 0)
    {
        n = n / 10;
        digits++;
    }
    int temp = originalNo;
    for (int i = 0; i < digits; i++)
    {
        int a = temp % 10;
        sum += pow(a, digits);
        temp = temp / 10;
    }
    cout << "sum : " << sum << endl;

    if (originalNo == sum)
    {
        return "it's a armstrong number";
    }
    else
    {
        return "sorrry";
    }
}

int main()
{
    cout << isArmstrongNumber(1634);
    // cout << gcd(100,250);
    return 0;
}