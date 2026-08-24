#include <iostream>
using namespace std;

void hanoi(int n, char source, char first, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    hanoi(n - 1, source, destination, first);

    cout << "Move disk " << n << " from " << source
         << " to " << destination << endl;

    hanoi(n - 1, first, source, destination);

}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    return 0;
}