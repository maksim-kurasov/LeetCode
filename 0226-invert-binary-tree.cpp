#include <bits/stdc++.h>

using namespace std;

/**
    Given the root of a binary tree, invert the tree, and return its root.

    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]

    Solution:
    Recursion, swap the branches each time, then repeat for the branches
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }
};

