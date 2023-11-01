#include <bits/stdc++.h>
#include "0104-maximum-depth-of-binary-tree.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;


int main() {
    ios

    Solution solution;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << solution.maxDepth(root);

    return 0;
}