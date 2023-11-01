#include <bits/stdc++.h>

using namespace std;

/**
    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.

    !!! You must solve the problem without modifying the array nums and uses only constant extra space.

    Input: nums = [1,3,4,2,2]
    Output: 2

    Solution:
    There are several ways to solve the problem:

        1. Using Linked List and Floyd's algorithm
            Array index - list value
            Array value - list next
            Search for an intersection point between fast and slow pointers, then
            move slow pointer to the beginning, then search for an intersection once more
            -> you've found the entry point to the cycle

        2. Negating numbers
            Negate number located in position val, if the number has already been negated,
            then it is the answer
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowP = 0,
            fastP = 0;

        // Searching for an intersection point between two pointers
        do {
            slowP = nums[slowP];
            fastP = nums[nums[fastP]];
        } while(slowP != fastP);

        // Searching for the point of cycle entry
        slowP = 0;
        while(slowP != fastP) {
            slowP = nums[slowP];
            fastP = nums[fastP];
        }

        return slowP;
    }
};

//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        int n = nums.size();
//        for(int i = 0; i < n; ++i) {
//            int val = abs(nums[i]);
//
//            nums[val] = -nums[val];
//            if(nums[val] > 0)
//                return val;
//        }
//    }
//};