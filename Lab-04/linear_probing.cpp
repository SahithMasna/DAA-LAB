#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter table size: ";
    cin >> n;

    int table[n];

    for (int i = 0; i < n; i++)
        table[i] = -1;

    int m;

    cout << "Enter number of elements: ";
    cin >> m;

    cout << "Enter elements:\n";

    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;

        int index = key % n;

        while (table[index] != -1)
            index = (index + 1) % n;

        table[index] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < n; i++)
        cout << i << " -> " << table[i] << endl;

    return 0;
}