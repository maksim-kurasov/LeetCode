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
    Remember max at each step
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
    int solution(TreeNode* root, int maxValue) {
        if(!root)
            return 0;

        int result = root->val >= maxValue;
        maxValue = max(maxValue, root->val);

        result += solution(root->left, maxValue);
        result += solution(root->right, maxValue);

        return result;
    }

    int goodNodes(TreeNode* root) {
        return solution(root, root->val);
    }
};