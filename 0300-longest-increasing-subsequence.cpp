#include <bits/stdc++.h>

using namespace std;

/**
    Given an integer array nums, return the length of the longest strictly increasing subsequence.

    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

    Solution:
    Piles + bin search
**/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> piles;
        piles.push_back(nums[0]);

        for(int i = 1; i < nums.size(); ++i) {
            int index = binSearch(piles, nums[i]);
            if(index >= piles.size())
                piles.push_back(nums[i]);
            else
                piles[index] = nums[i];
        }

        return piles.size();
    }

private:
    int binSearch(vector<int> &piles, int num) {
        int l = 0, r = piles.size() - 1;

        int m;
        while(l < r) {
            m = (l + r) / 2;

            if(num > piles[m])
                l = m + 1;
            else if(num < piles[m])
                r = m - 1;
            else
                return m;
        }

        m = (l + r) / 2;

        if(num > piles[m])
            return m + 1;
        return m;
    }
};
