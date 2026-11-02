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


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        else if (val > root->val) root->right = insertIntoBST(root->right, val);
        return root;
    }


    TreeNode* insertIntoBSTIter(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (!curr->left) { curr->left = new TreeNode(val); break; }
                curr = curr->left;
            } else if (val > curr->val) {
                if (!curr->right) { curr->right = new TreeNode(val); break; }
                curr = curr->right;
            } else break;
        }
        return root;
    }
};

static void inorder(TreeNode* n, vector<int>& out) {
    if (!n) return;
    inorder(n->left, out);
    out.push_back(n->val);
    inorder(n->right, out);
}
static vector<int> inorderOf(TreeNode* n) { vector<int> r; inorder(n, r); return r; }

static TreeNode* buildBST(const vector<int>& vals) {
    Solution s;
    TreeNode* root = nullptr;
    for (int v : vals) root = s.insertIntoBST(root, v);
    return root;
}

int main() {
    Solution s;


    TreeNode* t = buildBST({4, 2, 7, 1, 3, 6, 9});
    CHECK(t->val == 4 && t->left->val == 2 && t->right->val == 7);
    CHECK(t->left->left->val == 1 && t->left->right->val == 3);
    CHECK(t->right->left->val == 6 && t->right->right->val == 9);
    CHECK(inorderOf(t) == vector<int>({1, 2, 3, 4, 6, 7, 9}));
    freeTree(t);


    t = buildBST({4, 2, 7, 1, 3, 6, 9});
    t = s.insertIntoBST(t, 5);
    CHECK(t->right->left->left && t->right->left->left->val == 5);
    freeTree(t);


    CHECK(buildBST({}) == nullptr);
    t = buildBST({8});
    CHECK(t->val == 8 && !t->left && !t->right);
    freeTree(t);
    t = buildBST({-3, -1, -2});
    CHECK(inorderOf(t) == vector<int>({-3, -2, -1}));
    freeTree(t);
    t = buildBST({2, 2, 2});
    CHECK(!t->left && !t->right);
    freeTree(t);


    t = buildBST({1, 2, 3, 4});
    for (TreeNode* c = t; c; c = c->right) CHECK(c->left == nullptr);
    CHECK(inorderOf(t) == vector<int>({1, 2, 3, 4}));
    freeTree(t);


    t = nullptr;
    for (int v : {4, 2, 7, 1, 3, 6, 9}) t = s.insertIntoBSTIter(t, v);
    CHECK(inorderOf(t) == vector<int>({1, 2, 3, 4, 6, 7, 9}));
    freeTree(t);


    t = buildTree({4, 2, 7, 1, 3});
    t = s.insertIntoBST(t, 5);
    CHECK(inorderOf(t) == vector<int>({1, 2, 3, 4, 5, 7}));
    freeTree(t);

    cout << "All tests passed\n";
    return 0;
}
