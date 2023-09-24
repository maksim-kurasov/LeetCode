#include <bits/stdc++.h>

using namespace std;

/*
    Given an array of integers nums and an integer target, return indices of
    the two numbers such that they add up to target.

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]

    Evaluate compliment at each step and see if the compliment is in the array
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> counter;
        for(int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if(counter.find(compliment) != counter.end()) {
                return {i, counter[compliment]};
            }
            counter[nums[i]] = i;
        }
        return {-1, -1};
    }
};
