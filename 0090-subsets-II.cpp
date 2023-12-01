#include <bits/stdc++.h>

using namespace std;

/**
    Given an integer array nums that may contain duplicates, return all possible subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    Solution:
    Sort the array to detect duplicates easily (if nums[i] == nums[i - 1] then continue)
    At each step include [current], add element to [current] and backtrack
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());

        backtrack(ans, cur, nums, 0);

        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums, int pos) {
        ans.push_back(cur);
        for(int i = pos; i < nums.size(); ++i) {
            if(i != pos && nums[i] == nums[i - 1])
                continue;

            cur.push_back(nums[i]);
            backtrack(ans, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};

/**
int main() {
    vector<int> nums = {1, 2, 2};

    Solution solution;
    auto ans = solution.subsetsWithDup(nums);
}
**/