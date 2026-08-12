#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the value of k: ";
    cin >> k;

    sort(arr, arr + n);

    cout << k << "th smallest element = " << arr[k - 1];

    return 0;
}
