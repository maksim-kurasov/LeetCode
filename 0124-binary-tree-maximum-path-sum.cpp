#include <bits/stdc++.h>

using namespace std;

/**
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
    in the sequence has an edge connecting them. A node can only appear in the sequence
    at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.

    Input: root = [-10,9,20,null,null,15,7]
    Output: 42
    Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

    Solution:
    At each step we calculate [MAX without splitting] and [MAX with splitting]
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
    int solution(TreeNode* root, int &best) {
        if(root == nullptr)
            return 0;

        int left = max(0, solution(root->left, best)),
            right = max(0, solution(root->right, best)),
            center = root->val;

        best = max(best, left + center + right);

        return center + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int best = -1001;
        solution(root, best);

        return best;
    }
};