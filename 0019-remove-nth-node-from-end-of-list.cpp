#include <bits/stdc++.h>

using namespace std;

/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Solution:
    Calculate size, then find pos of the element, then remove the element
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = head;

        // Calculating size
        int size = 0;
        while(head) {
            head = head->next;
            ++size;
        }
        size -= n;
        head = ans;

        // Finding an element
        ListNode* prev = nullptr;
        while(size--) {
            prev = head;
            head = head->next;
        }

        // Deleting an element
        if(prev == nullptr)
            ans = ans->next;
        else if(head->next == nullptr)
            prev->next = nullptr;
        else
            prev->next = head->next;

        return ans;
    }
};