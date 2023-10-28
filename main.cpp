#include <bits/stdc++.h>
#include "0002-add-two-numbers.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    Solution solution;
    ListNode* a = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* b = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* c = solution.addTwoNumbers(a, b);
    while(c) {
        cout << c->val << " ";
        c = c->next;
    }

    return 0;
}