#include <bits/stdc++.h>

using namespace std;

/*
    Given an integer array nums, return an array answer such that answer[i]
    is equal to the product of all the elements of nums except nums[i].

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Create two PREFIX arrays: left and right. Current element's product except self will be the
    product of the corresponding elements in both arrays
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int leftProduct[n], rightProduct[n];

        leftProduct[0] = 1;
        for(int i = 1; i < n; ++i) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        rightProduct[n - 1] = 1;
        for(int i = n - 2; i >= 0; --i) {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; ++i) {
            ans[i] = leftProduct[i] * rightProduct[i];
        }
        return ans;
    }
};
