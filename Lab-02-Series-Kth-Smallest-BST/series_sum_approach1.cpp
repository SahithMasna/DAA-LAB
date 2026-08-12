#include <iostream>
using namespace std;

int main()
{
    int x, n;
    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the value of n: ";
    cin >> n;

    long long sum = 1;
    long long term = 1;

    for (int i = 1; i <= n; i++)
    {
        term *= x;
        sum += term;
    }

    cout << "Sum of the series = " << sum;

    return 0;
}
