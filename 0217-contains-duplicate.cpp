#include <bits/stdc++.h>

using namespace std;

/*
    Given an integer array nums, return true if any value appears at least twice in the array,
    and return false if every element is distinct.

    Input: nums = [1,2,3,1]
    Output: true

    Unordered Set has a property of containing only one instance of a particular number
    So we load all the numbers into the set and then compare its length with the original vector's length
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> setNums;
        for(int num : nums) {
            setNums.insert(num);
        }
        return nums.size() != setNums.size();
    }
};

