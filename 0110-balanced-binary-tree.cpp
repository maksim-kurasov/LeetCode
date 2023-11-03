#include <bits/stdc++.h>

using namespace std;

/**
    Given a binary tree, determine if it is height-balanced.

    Input: root = [3,9,20,null,null,15,7]
    Output: true

    Solution:
    We save the height of each tree and change its condition if
    the child nodes differ more than 1
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode *root, bool &cond) {
        if(!root)
            return 0;

        int left = dfs(root->left, cond);
        int right = dfs(root->right, cond);

        if(abs(left - right) > 1)
            cond = false;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool cond = true;

        dfs(root, cond);
        return cond;
    }
};