#include <bits/stdc++.h>

using namespace std;

/**
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

    - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

    - int get(int key) Return the value of the key if the key exists, otherwise return -1.

    - void put(int key, int value) Update the value of the key if the key exists. Otherwise,
    add the key-value pair to the cache. If the number of keys exceeds the capacity from
    this operation, evict the least recently used key.

    The functions get and put must each run in O(1) average time complexity.

    Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, null, -1, 3, 4]

    Solution:

*/

class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right; right->prev = left;
    }

    void remove(Node* node) {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node *prev = right->prev;
        Node *next = right;
        prev->next = node; next->prev = node;
        node->next = next; node->prev = prev;
    }

    int get(int key) {
        if(keys.contains(key)) {
            remove(keys[key]);
            insert(keys[key]);
            return keys[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(keys.contains(key))
            remove(keys[key]);
        keys[key] = new Node(key, value);
        insert(keys[key]);

        if(keys.size() > capacity) {
            Node *lru = left->next;
            remove(lru);
            keys.erase(lru->key);
        }
    }
private:
    Node *left, *right;
    unordered_map<int, Node*> keys;
    int capacity;
};