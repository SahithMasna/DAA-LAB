#include <iostream>
#include <climits>
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

    int previousMin = INT_MIN;
    int currentMin = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        currentMin = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] > previousMin && arr[j] < currentMin)
            {
                currentMin = arr[j];
            }
        }

        previousMin = currentMin;
    }

    cout << k << "th smallest element = " << previousMin;

    return 0;
}
