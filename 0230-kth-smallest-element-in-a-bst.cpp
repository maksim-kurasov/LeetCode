#include <bits/stdc++.h>

using namespace std;

/**
    Given the root of a binary search tree, and an integer k, return the kth smallest
    value (1-indexed) of all the values of the nodes in the tree.

    Input: root = [3,1,4,null,2], k = 1
    Output: 1

    Solution:
    Count elements, when count == k return the element
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
    int solution(TreeNode* root, int k, int &counter, int &ans) {
        if(!root)
            return 0;

        solution(root->left, k, counter, ans);

        if(++counter == k)
            ans = root->val;

        solution(root->right, k, counter, ans);

        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, counter = 0;
        solution(root, k, counter, ans);
        return ans;
    }
};