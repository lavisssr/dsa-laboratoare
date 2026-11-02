#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};

int main() {
    Solution s;
    vector<int> a = {3,2,2,3};
    int k = s.removeElement(a, 3);
    cout << "k=" << k << " : ";
    for (int i = 0; i < k; i++) cout << a[i] << ' ';
    cout << '\n';
    vector<int> b = {0,1,2,2,3,0,4,2};
    k = s.removeElement(b, 2);
    cout << "k=" << k << " : ";
    for (int i = 0; i < k; i++) cout << b[i] << ' ';
    cout << '\n';
    return 0;
}
