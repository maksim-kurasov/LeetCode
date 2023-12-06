#include <bits/stdc++.h>

using namespace std;

/**
    Design a class to find the kth largest element in a stream. Note that it is the kth
    largest element in the sorted order, not the kth distinct element.

    Implement KthLargest class:

    - KthLargest(int k, int[] nums) Initializes the object with the integer k and the
      stream of integers nums.

    - int add(int val) Appends the integer val to the stream and returns the element
      representing the kth largest element in the stream.

    Input
        ["KthLargest", "add", "add", "add", "add", "add"]
        [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
    Output
        [null, 4, 5, 5, 8, 8]

    Solution:
    Use priority queue of size k
**/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<>> queue;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int num : nums)
            add(num);
    }

    int add(int val) {
        queue.push(val);
        if(queue.size() == k)
            queue.pop();

        return queue.top();
    }
};
