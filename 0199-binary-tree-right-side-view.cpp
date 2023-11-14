#include <bits/stdc++.h>

using namespace std;

/**
    Given the root of a binary tree, imagine yourself standing on the
    right side of it, return the values of the nodes you can see ordered
    from top to bottom.

    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]

    Solution:
    Breadth-First Search, use deque, always choose rightmost element
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        deque<TreeNode*> dq;
        if(root) dq.push_back(root); // [2 3]

        while(!dq.empty()) {
            ans.push_back(dq.back()->val);

            for(auto &t : dq) {
                if(t->left) dq.push_back(t->left);
                if(t->right) dq.push_back(t->right);

                dq.pop_front();
            }
        }

        return ans;
    }
};