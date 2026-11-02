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
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

int main() {
    Solution s;

    TreeNode* bst = buildTree({4, 2, 7, 1, 3, 6, 9});
    CHECK(s.inorderTraversal(bst) == vector<int>({1, 2, 3, 4, 6, 7, 9}));
    CHECK(bst->val == 4 && bst->left->val == 2 && bst->right->val == 7);
    freeTree(bst);


    TreeNode* t = buildTree({2, 1, 3, 4});
    CHECK(s.inorderTraversal(t) == vector<int>({4, 1, 2, 3}));
    freeTree(t);

    CHECK(s.inorderTraversal(nullptr).empty());
    t = buildTree({1});
    CHECK(s.inorderTraversal(t) == vector<int>({1}));
    freeTree(t);
    t = buildTree({1, 2, N, 3});
    CHECK(s.inorderTraversal(t) == vector<int>({3, 2, 1}));
    freeTree(t);
    t = buildTree({1, N, 2, N, 3});
    CHECK(s.inorderTraversal(t) == vector<int>({1, 2, 3}));
    freeTree(t);


    t = buildTree({1, N, 2, 3});
    CHECK(s.inorderTraversal(t) == vector<int>({1, 3, 2}));
    freeTree(t);
    t = buildTree({1, 2, 3, 4, 5, N, 8, N, N, 6, 7, 9});
    CHECK(s.inorderTraversal(t) == vector<int>({4, 2, 6, 5, 7, 1, 3, 9, 8}));
    freeTree(t);

    cout << "All tests passed\n";
    return 0;
}
