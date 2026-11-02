#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) nums[i] += nums[i - 1];
        return nums;
    }
};

int main() {
    Solution s;
    vector<vector<int>> tests = {{1,2,3,4}, {1,1,1,1,1}, {3,1,2,10,1}};
    for (auto& t : tests) {
        for (int x : s.runningSum(t)) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
