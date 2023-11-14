#include <bits/stdc++.h>

using namespace std;

/**
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:
        1. The left subtree of a node contains only nodes with keys less than the node's key.
        2. The right subtree of a node contains only nodes with keys greater than the node's key.
        3. Both the left and right subtrees must also be binary search trees.

    Input: root = [2,1,3]
    Output: true

    Solution:
    Remember floor and ceiling at each step,
    if floor < elem < ceiling then its OK
    else the tree is invalid
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
    bool solution(TreeNode* root, long floor, long ceiling) {
        if(!root)
            return true;

        if(floor < root->val && root->val < ceiling)
            return solution(root->left, floor, root->val) && solution(root->right, root->val, ceiling);
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return solution(root, LONG_MIN, LONG_MAX);
    }
};