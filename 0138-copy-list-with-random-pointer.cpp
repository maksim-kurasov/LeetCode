#include <bits/stdc++.h>

using namespace std;

/**
    Construct a deep copy of the list.

    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Solution:
    First, copy the structure as if it was an ordinary linked list (i.e. copy "val" and "next")
    While copying, remember the bonds between old nodes and new ones in unordered_map
    Iterate the copied list and set "random" pointers
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;

        Node* copy = new Node(head->val);
        Node* ans = copy;

        // mp contains bonds between the nodes of new Random list and old one
        unordered_map<Node*, Node*> mp;

        // Copy "val" and "next"
        Node* cur = head;
        mp[cur] = copy;
        while(cur->next) {
            copy->next = new Node(cur->next->val);
            copy = copy->next;
            cur = cur->next;
            mp[cur] = copy; // Remember "random"
        }

        // Copy "random"
        cur = head;
        while(cur) {
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }

        return ans;
    }
};