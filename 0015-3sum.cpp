#include <bits/stdc++.h>

using namespace std;

/*
    Given an integer array nums, return all the triplets
    [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

    Two pointers + seen set + sort array
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<tuple<int, int, int>> seen;
        for(int i = 0; i < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum < 0) ++l;
                else if(sum > 0) --r;
                else {
                    seen.insert({nums[i], nums[l], nums[r]});
                    ++l; --r;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto& triplet : seen) {
            ans.push_back({get<0>(triplet), get<1>(triplet), get<2>(triplet)});
        }
        return ans;
    }
};