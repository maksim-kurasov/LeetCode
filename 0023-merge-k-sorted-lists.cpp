#include <bits/stdc++.h>

#include <utility>

using namespace std;

/**
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.

    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6

    Solution:
    There are two solutions to the problem.
        1. Using minHeap a.k.a priority queue
        2. Using mergeSort
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Creating pq and compare function
        auto compare = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> queue(compare);

        // Adding elements to the pq
        for(ListNode *list : lists) {
            while(list) {
                queue.push(list);
                list = list->next;
            }
        }

        // Move ->next pointers, make answer
        ListNode *ans = new ListNode();
        ListNode *dummy = ans;
        while(!queue.empty()) {
            dummy->next = queue.top();
            queue.pop();
            dummy = dummy->next;
        }
        dummy->next = nullptr;

        return ans->next;
    }
};

//class Solution {
//public:
//    // Function to merge two ListNodes
//    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
//        ListNode *ans = new ListNode();
//        ListNode *dummy = ans;
//        while(l1 && l2) {
//            if(l1->val < l2->val) {
//                dummy->next = l1;
//                l1 = l1->next;
//            }
//            else {
//                dummy->next = l2;
//                l2 = l2->next;
//            }
//            dummy = dummy->next;
//        }
//        if(l1)
//            dummy->next = l1;
//        else if(l2)
//            dummy->next = l2;
//
//        return ans->next;
//    }
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if(lists.empty())
//            return nullptr;
//
//        // Merge all ListNodes with each other O(nlogn)
//        while(lists.size() > 1) {
//            vector<ListNode*> mergedLists;
//            for(int i = 0; i < lists.size(); i += 2) {
//                ListNode *l1 = lists[i];
//                ListNode *l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
//
//                ListNode *l = mergeTwoLists(l1, l2);
//                mergedLists.push_back(l);
//            }
//            lists = mergedLists;
//        }
//
//        return lists[0];
//    }
//};