#include <bits/stdc++.h>

using namespace std;

/*
    Given an array of integers nums which is sorted in ascending order, and
    an integer target, write a function to search target in nums. If target exists,
    then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4

    Solution:
    Binary search
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int c = (l + r) / 2;
            if(target > nums[c])
                l = c + 1;
            else if(target < nums[c])
                r = c - 1;
            else
                return c;
        }
        return -1;
    }
};