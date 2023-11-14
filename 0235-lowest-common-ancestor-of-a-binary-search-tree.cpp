#include <bits/stdc++.h>

using namespace std;

/**
    Given a binary search tree (BST), find the lowest common ancestor
    (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common
    ancestor is defined between two nodes p and q as the lowest node in
    T that has both p and q as descendants (where we allow a node to be
    a descendant of itself).”

    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.

    Solution:
    If [curr < p] and [curr < q], we go right
    If [curr > p] and [curr > q], we go left
    If [p <= curr <= q], return curr
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(p->val > root->val && q->val > root->val)
                root = root->right;
            else if(p->val < root->val && q->val < root->val)
                root = root->left;
            else
                break;
        }

        return root;
    }
};