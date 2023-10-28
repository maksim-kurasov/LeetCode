#include <bits/stdc++.h>

using namespace std;

/**
    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached
    again by continuously following the next pointer. Internally, pos is used to denote the
    index of the node that tail's next pointer is connected to. Note that pos is not passed
    as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    Solution:
    Floyd's tortoise and hare algorithm. We use slow pointer and fast pointer
        1. If they meet, the list has a cycle
        2. If the fast pointer points to nullptr then the list does not have a cycle
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
    bool hasCycle(ListNode *head) {
        ListNode *slowP = head,
                 *fastP = head;

        while(fastP && fastP->next) {
            slowP = slowP->next;
            fastP = fastP->next->next;

            if(slowP == fastP)
                return true;
        }

        return false;
    }
};