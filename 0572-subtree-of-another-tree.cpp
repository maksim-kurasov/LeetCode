#include <bits/stdc++.h>

using namespace std;

/**
    Given the roots of two binary trees root and subRoot, return true
    if there is a subtree of root with the same structure and node values
    of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree
    and all of this node's descendants. The tree tree could also be considered
    as a subtree of itself.

    Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    Output: true

    Solution:
    Check if the tree is the same, then repeat for children
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;

        if(p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;

        if(isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};