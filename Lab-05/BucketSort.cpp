#include <iostream>
#include <vector>
using namespace std;

void bucketSort(int a[], int n)
{
    int maxValue = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxValue)
            maxValue = a[i];
    }

    vector<int> bucket(maxValue + 1, 0);

    for (int i = 0; i < n; i++)
        bucket[a[i]]++;

    int k = 0;

    for (int i = 0; i <= maxValue; i++)
    {
        while (bucket[i] > 0)
        {
            a[k++] = i;
            bucket[i]--;
        }
    }
}

int main()
{
    int n, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter non-negative elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bucketSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}