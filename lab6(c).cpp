#include <bits/stdc++.h>
using namespace std;

#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int N = INT_MIN;


TreeNode* buildTree(const vector<int>& v) {
    if (v.empty() || v[0] == N) return nullptr;
    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < v.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < v.size() && v[i] != N) { node->left = new TreeNode(v[i]); q.push(node->left); }
        i++;
        if (i < v.size() && v[i] != N) { node->right = new TreeNode(v[i]); q.push(node->right); }
        i++;
    }
    return root;
}

void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};

int main() {
    Solution s;
    typedef vector<vector<int>> VV;

    TreeNode* bst = buildTree({4, 2, 7, 1, 3, 6, 9});
    CHECK(s.levelOrder(bst) == VV({{4}, {2, 7}, {1, 3, 6, 9}}));
    CHECK(bst->val == 4 && bst->left->val == 2 && bst->right->val == 7);
    freeTree(bst);

    TreeNode* t = buildTree({2, 1, 3, 4});
    CHECK(s.levelOrder(t) == VV({{2}, {1, 3}, {4}}));
    freeTree(t);

    CHECK(s.levelOrder(nullptr).empty());
    t = buildTree({1});
    CHECK(s.levelOrder(t) == VV({{1}}));
    freeTree(t);
    t = buildTree({1, 2, N, 3});
    CHECK(s.levelOrder(t) == VV({{1}, {2}, {3}}));
    freeTree(t);

    t = buildTree({3, 9, 20, N, N, 15, 7});
    CHECK(s.levelOrder(t) == VV({{3}, {9, 20}, {15, 7}}));
    freeTree(t);

    cout << "All tests passed\n";
    return 0;
}
