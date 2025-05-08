#include <iostream>

using namespace std;

// Simple bubble sort
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Remove duplicates from sorted array
int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int j = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1; // new length
}

int main() {
    int n;
    cout << "Enter number of transaction IDs: ";
    cin >> n;

    int arr[1000]; // Assuming max 1000 IDs

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortArray(arr, n);
    int newSize = removeDuplicates(arr, n);

    cout << "\nUnique transaction IDs in sorted order:\n";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}