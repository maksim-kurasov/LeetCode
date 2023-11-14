#include <bits/stdc++.h>
#include "0235-lowest-common-ancestor-of-a-binary-search-tree.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;


int main() {
    ios

    Solution solution;
    TreeNode *right = new TreeNode(4, new TreeNode(3), new TreeNode(5));
    TreeNode *left = new TreeNode(2, new TreeNode(0), right);

    TreeNode *root = new TreeNode(6, left, new TreeNode(8, new TreeNode(4), new TreeNode(9)));
    cout << solution.lowestCommonAncestor(root, left, right)->val;

    return 0;
}