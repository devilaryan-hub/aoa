#include <stdio.h>

int set[] = {2, 3, 4, 5}, sel[20], n = 4, target = 7;

void sumOfSubset(int idx, int sum, int len) {
    if (sum == target) {
        printf("Subset: { ");
        for (int i = 0; i < len; i++) printf("%d ", sel[i]);
        printf("}\n");
        return;
    }
    if (idx == n || sum > target) return;

    sel[len] = set[idx];
    sumOfSubset(idx + 1, sum + set[idx], len + 1); // Include
    sumOfSubset(idx + 1, sum, len);               // Exclude
}

int main() {
    sumOfSubset(0, 0, 0);
    return 0;
}
