#include <bits/stdc++.h>

using namespace std;

/**
    Given two integer arrays preorder and inorder where preorder is
    the preorder traversal of a binary tree and inorder is the inorder
    traversal of the same tree, construct and return the binary tree.

    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]

    Solution:
    First element in [preorder] is always root element,
    Find index of this root in [inorder]:
        elements BEFORE the index are left children
        elements AFTER the index are right children
    Repeat recursively
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
    TreeNode* solution(vector<int>& preorder, vector<int>& inorder,
                       int preorderStart, int preorderEnd, int inorderStart, int inorderEnd) {
        if(preorderEnd <= preorderStart || inorderEnd <= inorderStart)
            return nullptr;

        auto root = new TreeNode(preorder[preorderStart]);
        int rootIndex = 0;
        for(int i = inorderStart; i < inorderEnd; ++i)
            if(root->val == inorder[i]) {
                rootIndex = i;
                break;
            }


        root->left = solution(preorder, inorder, preorderStart + 1, preorderStart + 1 + rootIndex - inorderStart, inorderStart, rootIndex);
        root->right = solution(preorder, inorder, preorderStart + 1 + rootIndex - inorderStart, preorderEnd, rootIndex + 1, inorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solution(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};