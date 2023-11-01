#include <bits/stdc++.h>
#include "0023-merge-k-sorted-lists.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;


int main() {
    ios

    Solution solution;
    ListNode *l1 = new ListNode(-1, new ListNode(-1, new ListNode(-1)));
    ListNode *l2 = new ListNode(-2, new ListNode(-2, new ListNode(-1)));
    vector<ListNode*> vec = {l1, l2};
    ListNode *ans = solution.mergeKLists(vec);

    return 0;
}