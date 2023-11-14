#include <bits/stdc++.h>
#include "0105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 100000000

using namespace std;


int main() {
    ios

    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode *ans = solution.buildTree(preorder, inorder);

    return 0;
}