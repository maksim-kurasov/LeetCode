#include <bits/stdc++.h>

using namespace std;

/**
    Given the head of a linked list, reverse the nodes of the list k at a time,
    and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked
    list. If the number of nodes is not a multiple of k then left-out nodes, in the
    end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]

    Solution:
    Reverse each group independently, then combine the groups
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
    // Reverse one group
    ListNode* reverseGroup(ListNode* head, int k) {
        ListNode *prev = nullptr;
        while(k--) {
            ListNode *memo = head->next;
            head->next = prev;
            prev = head;
            head = memo;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode();
        ListNode *temp = ans;
        while(head) {
            // Dummy points on an element after the group
            ListNode *dummy = head;
            int i;
            for(i = 0; i < k; ++i) {
                if(dummy)
                    dummy = dummy->next;
                else
                    break;
            }
            if(i == k) {
                // If complete group
                ListNode *l = head;
                temp->next = reverseGroup(head, k);
                temp = l;
                head = dummy;
            }
            else {
                // If incomplete group
                temp->next = head;
                head = nullptr;
            }
        }

        return ans->next;
    }
};

