#include <bits/stdc++.h>

using namespace std;

/**
    Given an array nums of n integers, return an array of
    all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
    such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.

    Solution:
    Fix a and b. Then use two pointers on a sorted array to find c and d.
    Skip repeating numbers.
**/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int a = 0; a < n - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < n - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int left = b + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[a] + nums[b] + nums[left] + nums[right];
                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        ans.push_back({nums[a], nums[b], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) ++left;
                        while(left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    }
                }
            }
        }
        return ans;
    }
};