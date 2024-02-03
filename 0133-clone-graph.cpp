#include <bits/stdc++.h>

using namespace std;

/**
    Given a reference of a node in a connected undirected graph.

    Return a deep copy (clone) of the graph.

    Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    Output: [[2,4],[1,3],[2,4],[1,3]]
    Explanation: There are 4 nodes in the graph.
    1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
    3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
    4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

    Solution:
    Keep track of visited nodes to avoid infinite cycles. Aside from that,
    just recursively copy each element.
**/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(mp.contains(node)) return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(auto neighbourNode : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbourNode));
        }

        return clone;
    }
private:
    unordered_map<Node*, Node*> mp;
};
