#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == key) return mid;
        if (key < a[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main() {
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}, n = 10, key = 23;
    int pos = binarySearch(a, n, key);
    if (pos != -1) printf("Element found at index %d\n", pos);
    else printf("Element not found\n");
    return 0;
}
