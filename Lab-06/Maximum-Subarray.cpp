#include <iostream>
using namespace std;

struct Result
{
    int left;
    int right;
    int sum;
};

Result maxCrossingSubarray(int a[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = -999999;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + a[i];

        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int rightSum = -999999;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + a[i];

        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    Result result;
    result.left = maxLeft;
    result.right = maxRight;
    result.sum = leftSum + rightSum;

    return result;
}

Result maxSubarray(int a[], int low, int high)
{
    // Only one element
    if (low == high)
    {
        Result result;
        result.left = low;
        result.right = high;
        result.sum = a[low];

        return result;
    }

    int mid = (low + high) / 2;

    // Find maximum subarray in left half
    Result leftResult = maxSubarray(a, low, mid);

    // Find maximum subarray in right half
    Result rightResult = maxSubarray(a, mid + 1, high);

    // Find maximum subarray crossing the middle
    Result crossResult =
        maxCrossingSubarray(a, low, mid, high);

    // Compare all three
    if (leftResult.sum >= rightResult.sum &&
        leftResult.sum >= crossResult.sum)
    {
        return leftResult;
    }
    else if (rightResult.sum >= leftResult.sum &&
             rightResult.sum >= crossResult.sum)
    {
        return rightResult;
    }
    else
    {
        return crossResult;
    }
}

int main()
{
    int a[] = {-2, 3, -1, 5, -6, 4};
    int n = 6;

    Result answer = maxSubarray(a, 0, n - 1);

    cout << "Maximum Subarray: ";

    for (int i = answer.left; i <= answer.right; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Maximum Sum = " << answer.sum << endl;

    return 0;
}