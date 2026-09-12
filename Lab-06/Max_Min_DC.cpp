#include <iostream>
using namespace std;

struct Result
{
    int min;
    int max;
};

Result Max_Min(int a[], int low, int high)
{
    Result result, left, right;

    if (low == high)
    {
        result.min = a[low];
        result.max = a[low];
        return result;
    }

 if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            result.min = a[low];
            result.max = a[high];
        }
        else
        {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
   left = Max_Min(a, low, mid);
   right = Max_Min(a,mid+1,high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}
int main()
{
    int n ;
    int a[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Result result = Max_Min(a, 0, n - 1);

    cout << "Minimum = " << result.min << endl;
    cout << "Maximum = " << result.max << endl;

    return 0;
}