#include <bits/stdc++.h>
#include "0138-copy-list-with-random-pointer.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    Solution solution;
    Node *a = new Node(7);
    a->random = NULL;
    Node *b = a;
    Node *memo;
    a->next = new Node(13); a->random = NULL; memo = a; a = a->next;
    a->next = new Node(11); a->random = memo; a = a->next;
    a->next = new Node(10); a = a->next;
    a->next = new Node(1);
    a = solution.copyRandomList(b);
    while(a) {
        cout << a->val << " ";
        a = a->next;
    }

    return 0;
}