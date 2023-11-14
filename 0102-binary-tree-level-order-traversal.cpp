#include <bits/stdc++.h>

using namespace std;

/**
    Given the root of a binary tree, return the level order traversal
    of its nodes' values. (i.e., from left to right, level by level).

    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

    Solution:
    Breadth-First Search
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()) {
            vector<int> vec;

            int size = q.size();
            while(size--) {
                vec.push_back(q.front()->val);

                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);

                q.pop();
            }

            ans.push_back(vec);
        }

        return ans;
    }
};