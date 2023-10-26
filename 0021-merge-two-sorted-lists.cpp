#include <bits/stdc++.h>

using namespace std;

/*
    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists into one sorted list. The list should be made by
    splicing together the nodes of the first two lists.

    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

    Solution:
    Basically two pointer approach. Always insert the lowest element first, then shift the pointer
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* actualAns = ans;
        while(list1 || list2) {
            if(!list1) {
                ans->next = list2;
                list2 = list2->next;
            }
            else if(!list2) {
                ans->next = list1;
                list1 = list1->next;
            }
            else {
                ans->next = (list1->val < list2->val) ? list1 : list2;
                (list1->val < list2->val) ? list1 = list1->next : list2 = list2->next;
            }
            ans = ans->next;
        }
        ans->next = nullptr;
        return actualAns->next;
    }
};