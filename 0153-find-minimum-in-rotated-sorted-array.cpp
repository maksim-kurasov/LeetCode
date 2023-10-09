#include <bits/stdc++.h>

using namespace std;

/*
    Suppose an array of length n sorted in ascending order is rotated between
    1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
     - [4,5,6,7,0,1,2] if it was rotated 4 times.
     - [0,1,2,4,5,6,7] if it was rotated 7 times.

    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time
    results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.

    You must write an algorithm that runs in O(log n) time.

    Input: nums = [3,4,5,1,2]
    Output: 1

    Solution:
    Binary search.
            1. If the left side is sorted, remember the min element and continue with the right side
            2. If not, remember the middle element and continue with the left side
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,
            r = nums.size() - 1;

        int ans = 5000;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums[mid] >= nums[l]) {
                ans = min(ans, nums[l]);
                l = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};