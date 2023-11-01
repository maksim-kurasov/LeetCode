#include <bits/stdc++.h>

using namespace std;

/**
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the
    longest path from the root node down to the farthest leaf node.

    Input: root = [3,9,20,null,null,15,7]
    Output: 3

    Solution:

*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive DFS
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Iterative DFS
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int ans = 0;
        while(!st.empty()) {
            auto [node, depth] = st.top(); st.pop();

            if(node) {
                ans = max(ans, depth);
                st.push({node->right, depth + 1});
                st.push({node->left, depth + 1});
            }
        }

        return ans;
    }
};

// BFS
class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        if(root)
            queue.push(root);

        int level = 0;

        while(!queue.empty()) {
            int size = queue.size();
            for(int i = 0; i < size; ++i) {
                TreeNode *node = queue.front();
                queue.pop();
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            ++level;
        }

        return level;
    }
};

