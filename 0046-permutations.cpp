#include <bits/stdc++.h>

using namespace std;

/**
    Given an array nums of distinct integers, return all the possible permutations.
    You can return the answer in any order.

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Solution:
    We make left side of array BACKTRACKED and work only with the right side
    lest we have to use additional memory to keep track of added elements
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        backtrack(ans, nums, 0);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &nums, int depth) {
        if(depth == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = depth; i < nums.size(); ++i) {
            swap(nums[depth], nums[i]);
            backtrack(ans, nums, depth + 1);
            swap(nums[depth], nums[i]);
        }
    }
};


int main() {
    vector<int> nums = {1, 2, 3};

    Solution solution;
    auto ans = solution.permute(nums);
}
