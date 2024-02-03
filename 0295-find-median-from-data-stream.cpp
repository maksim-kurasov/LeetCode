#include <bits/stdc++.h>

using namespace std;

/**
    Implement the MedianFinder class

    - For example, for arr = [2,3,4], the median is 3.
    - For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

    Input
    ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    [[], [1], [2], [], [3], []]
    Output
    [null, null, null, 1.5, null, 2.0]

    Solution:
    The idea is to keep 2 heaps: maxHeap (which holds the smaller half of
    the stream) and minHeap (which holds the larger one)

    Then we can just take .top() from both and calculate the median
**/

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if(!maxHeap.empty() && num < maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.size() != minHeap.size())
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, less<>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
};
