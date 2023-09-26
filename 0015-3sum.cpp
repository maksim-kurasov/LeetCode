#include <bits/stdc++.h>

using namespace std;

/*
    Given an integer array nums, return all the triplets
    [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

    Solution:
    1. Fix the first number
    2. Find twoSum with the rest of the array
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sort nums
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i) {
            // Nothing to compensate
            if(nums[i] > 0) break;

            // Ignore repeated
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // Two Sum
            int l = i + 1, r = nums.size() - 1;
            vector<int> triplet(3);
            while(l < r) {
                // Ignore repeated
                if(l > i + 1 && nums[l] == nums[l - 1]) {
                    ++l; continue;
                }

                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0)
                    ++l;
                else if(sum > 0)
                    --r;
                else {
                    triplet[0] = nums[i];
                    triplet[1] = nums[l];
                    triplet[2] = nums[r];
                    ans.push_back(triplet);
                    ++l; --r;
                }
            }
        }
        return ans;
    }
};