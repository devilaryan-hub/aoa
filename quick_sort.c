#include <stdio.h>

int partition(int a[], int lb, int ub) {
    int pivot = a[lb], start = lb, end = ub, temp;
    while (start < end) {
        while (a[start] <= pivot && start < ub) start++;
        while (a[end] > pivot) end--;
        if (start < end) {
            temp = a[start]; a[start] = a[end]; a[end] = temp;
        }
    }
    a[lb] = a[end]; a[end] = pivot;
    return end;
}

void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

int main() {
    int a[] = {24, 9, 29, 14, 39}, n = 5;
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
