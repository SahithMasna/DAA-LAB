#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, n;

    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the value of n: ";
    cin >> n;

    long long sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += pow(x, i);
    }

    cout << "Sum of the series = " << sum;

    return 0;
}
