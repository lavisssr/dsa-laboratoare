#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution s;
    vector<int> a = {1,2,3,0,0,0}, b = {2,5,6};
    s.merge(a, 3, b, 3);
    for (int x : a) cout << x << ' ';
    cout << '\n';
    vector<int> c = {1}, d = {};
    s.merge(c, 1, d, 0);
    for (int x : c) cout << x << ' ';
    cout << '\n';
    vector<int> e = {0}, f = {1};
    s.merge(e, 0, f, 1);
    for (int x : e) cout << x << ' ';
    cout << '\n';
    return 0;
}
