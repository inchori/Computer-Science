#include <iostream>
#include <algorithm>

using namespace std;

int n, key;
int arr[20], temp[20];

// Insertion Sort
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}