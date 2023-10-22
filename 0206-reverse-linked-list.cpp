#include <bits/stdc++.h>

using namespace std;

/*
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

    Solution:
    We should contain 1. copy list
                      2. previous element

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
    ListNode* reverseList(ListNode* head) {
        ListNode* copy = head;
        ListNode* prev = nullptr;
        while(copy) {
            head = copy;
            copy = copy->next;
            head->next = prev;
            prev = head;
        }
        return head;
    }
};