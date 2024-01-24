#include <bits/stdc++.h>

using namespace std;

/**
    Given an integer array nums and an integer k, return the kth largest element in the array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Can you solve it without sorting?

    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

    Solution:
    Quick Select of Priority Queue
**/

// Quick Select
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true) {
            int pivotIndex = left + rand() % (right - left + 1);
            partition(nums, left, right, pivotIndex);

            if(pivotIndex == nums.size() - k)
                return nums[pivotIndex];
            else if(pivotIndex > nums.size() - k)
                right = pivotIndex - 1;
            else
                left = pivotIndex + 1;
        }
    }

    void partition(vector<int> &nums, int left, int right, int &pivotIndex) {
        int pivot = nums[pivotIndex];

        swap(nums[pivotIndex], nums[right]);
        int j = left;
        for(int i = left; i < right; ++i) {
            if(nums[i] < pivot) {
                swap(nums[i], nums[j]);
                ++j;
            }
        }

        swap(nums[right], nums[j]);
        pivotIndex = j;
    }
};

// Min Heap
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> q(nums.begin(), nums.begin() + k);

        for(int i = k; i < nums.size(); ++i) {
            if(nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }

        return q.top();
    }
};

