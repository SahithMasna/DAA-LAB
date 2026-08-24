#include <iostream>
#include <cmath>
using namespace std;

void moveDisk(char from, char to)
{
    cout << "Move disk from " << from << " to " << to << endl;
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    int moves = pow(2, n) - 1;

    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    if (n % 2 == 0)
        swap(auxiliary, destination);

    for (int i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
            moveDisk(source, destination);
        else if (i % 3 == 2)
            moveDisk(source, auxiliary);
        else
            moveDisk(auxiliary, destination);
    }

    return 0;
}