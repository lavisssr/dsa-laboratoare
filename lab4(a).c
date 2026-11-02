#include <stdio.h>
#include <stdlib.h>

#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

int search(int *nums, int numsSize, int target) {
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return -1;
}

int main(void) {
    int v[] = {-1, 0, 3, 5, 9, 12};
    CHECK(search(v, 6, 9) == 4);
    CHECK(search(v, 6, 2) == -1);
    CHECK(search(v, 6, -1) == 0);
    CHECK(search(v, 6, 12) == 5);
    CHECK(search(v, 6, -5) == -1);
    CHECK(search(v, 6, 100) == -1);
    int one[] = {5};
    CHECK(search(one, 1, 5) == 0);
    CHECK(search(one, 1, 3) == -1);
    CHECK(search(v, 0, 1) == -1);
    printf("All tests passed\n");
    return 0;
}
