#include <stdio.h>
#include <stdlib.h>

#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

int searchInsert(int *nums, int numsSize, int target) {
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main(void) {
    int v[] = {1, 3, 5, 6};
    CHECK(searchInsert(v, 4, 5) == 2);
    CHECK(searchInsert(v, 4, 2) == 1);
    CHECK(searchInsert(v, 4, 0) == 0);
    CHECK(searchInsert(v, 4, 7) == 4);
    int one[] = {3};
    CHECK(searchInsert(one, 1, 3) == 0);
    CHECK(searchInsert(one, 1, 1) == 0);
    CHECK(searchInsert(one, 1, 9) == 1);
    CHECK(searchInsert(v, 0, 4) == 0);
    printf("All tests passed\n");
    return 0;
}
