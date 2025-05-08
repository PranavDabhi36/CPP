#include <iostream>
#include <algorithm> // for reverse
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Use reverse with pointers
    reverse(arr, arr + n);

    cout << "Reversed sequence:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
