#include <stdio.h>

void getMinMax(int a[], int l, int h, int *min, int *max) {
    if (l == h) {
        *min = *max = a[l];
    } else if (l == h - 1) {
        *min = (a[l] < a[h]) ? a[l] : a[h];
        *max = (a[l] > a[h]) ? a[l] : a[h];
    } else {
        int mid = (l + h) / 2, min1, max1, min2, max2;
        getMinMax(a, l, mid, &min1, &max1);
        getMinMax(a, mid + 1, h, &min2, &max2);
        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int a[] = {1000, 11, 445, 1, 330, 3000}, n = 6, min, max;
    getMinMax(a, 0, n - 1, &min, &max);
    printf("Min = %d, Max = %d\n", min, max);
    return 0;
}
