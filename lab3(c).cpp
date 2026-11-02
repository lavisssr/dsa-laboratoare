#include <bits/stdc++.h>
using namespace std;

#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

class Solution {

    void mergeSort(vector<int>& a, vector<int>& buf, int lo, int hi) {
        if (hi - lo < 2) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(a, buf, lo, mid);
        mergeSort(a, buf, mid, hi);
        int i = lo, j = mid, k = lo;
        while (i < mid && j < hi) buf[k++] = (a[j] < a[i]) ? a[j++] : a[i++];
        while (i < mid) buf[k++] = a[i++];
        while (j < hi) buf[k++] = a[j++];
        for (k = lo; k < hi; k++) a[k] = buf[k];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> buf(nums.size());
        mergeSort(nums, buf, 0, (int)nums.size());
        return nums;
    }
};

static void check(vector<int> v) {
    vector<int> expected = v;
    sort(expected.begin(), expected.end());
    Solution s;
    CHECK(s.sortArray(v) == expected);
}

int main() {
    check({6, 2, 5, 2, 1});
    check({7});
    check({-3, -1, -2, 0});
    check({2, 2, 1, 1, 3, 3});
    check({1, 2, 3, 4, 5});
    check({5, 4, 3, 2, 1});
    check({3, 1, 2});
    check({5, 1, 1, 2, 0, 0});
    cout << "All tests passed\n";
    return 0;
}
