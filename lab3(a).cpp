#include <bits/stdc++.h>
using namespace std;

#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        if (num % 2 == 0) return 1 + numberOfSteps(num / 2);
        return 1 + numberOfSteps(num - 1);
    }
};

int main() {
    Solution s;
    CHECK(s.numberOfSteps(0) == 0);
    CHECK(s.numberOfSteps(1) == 1);
    CHECK(s.numberOfSteps(8) == 4);
    CHECK(s.numberOfSteps(14) == 6);
    CHECK(s.numberOfSteps(123) == 12);
    cout << "All tests passed\n";
    return 0;
}
