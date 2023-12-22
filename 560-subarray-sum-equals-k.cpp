#include <bits/stdc++.h>

using namespace std;

/**
    Given an array of integers nums and an integer k, return the total number of
    subarrays whose sum equals to k.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Input: nums = [1,2,3], k = 3
    Output: 2

    Solution:
    Every subarray sum is the DIFFERENCE between two prefix sums
    So we keep all traversed prefix sums and their count in a map
    And when our current prefix sum falls short from k we look if we can make up for it
    using traversed prefix sums
**/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSums = {{0, 1}};

        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(prefixSums.contains(sum - k))
                ans += prefixSums[sum - k];

            ++prefixSums[sum];
        }

        return ans;
    }
};

