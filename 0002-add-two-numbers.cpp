#include <bits/stdc++.h>

using namespace std;

/**
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Solution:
    Create new list, evaluate each element using elements from l1 and l2 and carry
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* ans = sum;

        int carry = 0;
        while(l1 || l2 || carry) {
            // Evaluate digit and carry
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int val = val1 + val2 + carry;
            carry = val / 10;

            // Update sum
            sum->next = new ListNode(val % 10);
            sum = sum->next;

            // Update pointers
            l1 ? l1 = l1->next : nullptr;
            l2 ? l2 = l2->next : nullptr;
        }

        return ans->next;
    }
};