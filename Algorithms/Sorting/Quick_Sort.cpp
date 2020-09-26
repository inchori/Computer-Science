#include <iostream>

using namespace std;

int n, arr[20], temp[20];

// Quick Sort
int partition(int left, int right) {
    int pivot = arr[right];
    int lcnt = left - 1;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivot) {
            lcnt++;
            swap(arr[lcnt], arr[i]);
        }
    }
    swap(arr[lcnt + 1], arr[right]);
    return lcnt + 1;
}

void quick_sort(int left, int right) {
    if (left < right) {
        int q = partition(left, right);
        quick_sort(left, q - 1);
        quick_sort(q + 1, right);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}