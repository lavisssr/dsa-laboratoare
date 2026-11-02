#include <stdio.h>
#include <stdlib.h>

#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
    int boundary = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            int t = nums[boundary]; nums[boundary] = nums[i]; nums[i] = t;
            boundary++;
        }
    }
    *returnSize = numsSize;
    return nums;
}

static void check(int *v, int n, int evens) {
    int size;
    int *r = sortArrayByParity(v, n, &size);
    CHECK(size == n);
    for (int i = 0; i < evens; i++) CHECK(r[i] % 2 == 0);
    for (int i = evens; i < n; i++) CHECK(r[i] % 2 == 1);
}

int main(void) {
    int a[] = {3, 1, 2, 4};  check(a, 4, 2);
    int b[] = {0};           check(b, 1, 1);
    int c[] = {1, 3, 5};     check(c, 3, 0);
    int d[] = {2, 4, 6};     check(d, 3, 3);
    printf("All tests passed\n");
    return 0;
}
