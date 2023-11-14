#include <bits/stdc++.h>

using namespace std;

/**
    Given a binary tree root, a node X in the tree is named
    good if in the path from root to X there are no nodes with
    a value greater than X.

    Return the number of good nodes in the binary tree.

    Input: root = [3,1,4,3,null,1,5]
    Output: 4
    Explanation: Nodes in blue are good.

    Solution:
    Remember max at each step, make ans counter global
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
    void solution(TreeNode* root, int max, int &ans) {
        if(!root)
            return;

        if(root->val >= max) {
            max = root->val;
            ++ans;
        }

        solution(root->left, max, ans);
        solution(root->right, max, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        solution(root, INT_MIN, ans);

        return ans;
    }
};