#include <bits/stdc++.h>
#include "0019-remove-nth-node-from-end-of-list.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    Solution solution;
    ListNode *a = new ListNode(1, new ListNode(2));
    a = solution.removeNthFromEnd(a, 1);
    while(a) {
        cout << a->val << " ";
        a = a->next;
    }

    return 0;
}