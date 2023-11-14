#include <bits/stdc++.h>
#include "1448-count-good-nodes-in-binary-tree.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 100000000

using namespace std;


int main() {
    ios

    Solution solution;
    TreeNode *root = new TreeNode(3, new TreeNode(1, new TreeNode(3), nullptr), new TreeNode(4, new TreeNode(1), new TreeNode(5)));
    cout << solution.goodNodes(root);

    return 0;
}