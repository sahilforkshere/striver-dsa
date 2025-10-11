#include <iostream>
using namespace std;

void rev(int l, int r, int arr[]) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    rev(l + 1, r - 1, arr);
}

int main() {
    int arr[] = {5, 3, 2, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before reversing: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    rev(0, n - 1, arr);

    cout << "After reversing: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
 