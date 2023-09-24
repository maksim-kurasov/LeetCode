#include <bits/stdc++.h>

using namespace std;

/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:
        - MinStack() initializes the stack object.
        - void push(int val) pushes the element val onto the stack.
        - void pop() removes the element on the top of the stack.
        - int top() gets the top element of the stack.
        - int getMin() retrieves the minimum element in the stack.

    You must implement a solution with O(1) time complexity for each function.

    Input:
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output:
    [null,null,null,null,-3,null,0,-2]

    Solution:
    Calculate the minimum in each node when the node is created
*/

class MinStack {
private:
    class Node {
    public:
        int value;
        int minElement;
        Node *next;

        Node(int value, int minElement, Node *next) {
            this->value = value;
            this->minElement = minElement;
            this->next = next;
        }
    };

    Node *stackHead;
public:
    MinStack() {
        stackHead = NULL;
    }

    void push(int val) {
        stackHead = new Node(val, stackHead ? min(val, stackHead->minElement) : val, stackHead);
    }

    void pop() {
        stackHead = stackHead->next;
    }

    int top() {
        return stackHead->value;
    }

    int getMin() {
        return stackHead->minElement;
    }
};
