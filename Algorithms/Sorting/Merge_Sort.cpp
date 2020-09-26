#include <iostream>

using namespace std;

int n, arr[20], temp[20];

// Merge Sort
void Merge(int left, int mid, int right) {
    int lcnt = left, rcnt = mid + 1, k = left;
    while (lcnt <= mid && rcnt <= right) {
        if (arr[lcnt] <= arr[rcnt]) temp[k++] = arr[lcnt++];
        else temp[k++] = arr[rcnt++];
    }
    if (mid < lcnt) {
        for (int i = rcnt; i <= right; i++) {
            temp[k++] = arr[i];
        }
    } else {
        for (int i = lcnt; i <= mid; i++) {
            temp[k++] = arr[i];
        }
    }
    for (int i = left; i <= right; i++) arr[i] = temp[i];
}

void merge_sort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        Merge(left, mid, right);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}