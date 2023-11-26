#include <bits/stdc++.h>
#include "0124-binary-tree-maximum-path-sum.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 100000000

using namespace std;


int main() {
    ios

    Solution solution;
    TreeNode *tree = new TreeNode(1, new TreeNode(-2, new TreeNode(1, new TreeNode(-1), nullptr), new TreeNode(3)), new TreeNode(-3, new TreeNode(-2), nullptr));

    cout << solution.maxPathSum(tree);

    return 0;
}