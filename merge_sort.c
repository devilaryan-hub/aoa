#include <stdio.h>

void merge(int a[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb, b[50];
    while (i <= mid && j <= ub)
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) b[k++] = a[i++];
    while (j <= ub) b[k++] = a[j++];
    for (k = lb; k <= ub; k++) a[k] = b[k];
}

void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10}, n = 7;
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
