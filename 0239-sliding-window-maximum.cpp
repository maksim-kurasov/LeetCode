#include <bits/stdc++.h>

using namespace std;

/*
    You are given an array of integers nums, there is a sliding window
    of size k which is moving from the very left of the array to the
    very right. You can only see the k numbers in the window.
    Each time the sliding window moves right by one position.

    Return the max sliding window.

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]

    Solution:
    So we need a data structure, which    1. Can peek and delete a beginning element in O(1)
                                          2. Can insert an element to the end in O(1)
                                          3. Can keep track of the largest element (max in O(1))
    Therefore we use monotonic decreasing deque
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        deque<int> dq;

        dq.push_back(nums[0]);
        for(int i = 1; i < k; ++i) {
            while(!dq.empty() && dq.back() <= nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans[0] = dq.front();

        for(int i = 1; i < nums.size() - k + 1; ++i) {
            if(!dq.empty() && dq.front() == nums[i - 1])
                dq.pop_front();

            while(!dq.empty() && dq.back() < nums[i + k - 1])
                dq.pop_back();

            dq.push_back(nums[i + k - 1]);
            ans[i] = dq.front();
        }
        return ans;
    }
};