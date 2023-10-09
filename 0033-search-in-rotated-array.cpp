#include <bits/stdc++.h>

using namespace std;

/*
    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an
    unknown pivot index k (1 <= k < nums.length) such that the resulting array is
    [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
    For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the
    index of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    Solution:
    Binary search.
            1. If the left side is sorted AND target IS in left side, we continue on with the left side
            2. If the left side is sorted AND target IS NOT in left side, we continue on with the right side
            3. If the right side is sorted AND target IS in right side, we continue on with the right side
            4. If the right side is sorted AND target IS NOT in right side, we continue on with the left side
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,
            r = nums.size() - 1;

        int mid;
        while(l <= r) {
            mid = (l + r) / 2;

            if(nums[mid] == target)
                return mid;

            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else {
                if(nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};