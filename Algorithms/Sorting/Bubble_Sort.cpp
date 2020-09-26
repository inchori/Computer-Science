#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20], temp[20];


// Bubble Sort
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
            else continue;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}