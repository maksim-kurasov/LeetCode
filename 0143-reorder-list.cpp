#include <bits/stdc++.h>

using namespace std;

/*
    You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]

    Solution:
    Find the middle using slow and fast pointers. Reverse the second half. Merge both halfs together.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)
            return;

        // Find the middle
        ListNode* slowP = head;
        ListNode* fastP = head->next;
        while(fastP != nullptr && fastP->next != nullptr) {
            slowP = slowP->next;
            fastP = fastP->next->next;
        }

        // Reverse the second half
        fastP = slowP->next;
        ListNode* prev = nullptr;
        while(fastP) {
            ListNode* nxtP = fastP->next;
            fastP->next = prev;
            prev = fastP;
            fastP = nxtP;
        }
        fastP = prev;

        // Restrain the first half
        slowP->next = nullptr;
        slowP = head;

        // Merge two halfs
        ListNode *memoFirst, *memoSecond;
        while(fastP != nullptr) {
            memoFirst = slowP->next;
            memoSecond = fastP->next;

            slowP->next = fastP;
            fastP->next = memoFirst;

            slowP = memoFirst;
            fastP = memoSecond;
        }
    }
};