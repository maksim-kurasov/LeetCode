#include <bits/stdc++.h>
#include "0025-reverse-nodes-in-k-group.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;


int main() {
    ios

    Solution solution;
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode* vec = solution.reverseKGroup(l1, 2);

    return 0;
}