#include <bits/stdc++.h>
#include "0143-reorder-list.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    Solution solution;
    ListNode *a = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    solution.reorderList(a);
    while(a) {
        cout << a->val << " ";
        a = a->next;
    }

    return 0;
}