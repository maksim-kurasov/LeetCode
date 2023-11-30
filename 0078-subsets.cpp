#include <bits/stdc++.h>

using namespace std;

/**
    Given an integer array nums of unique elements, return all possible subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    Solution:
    Backtracking
        [ ]
        [1], [1, 2], [1, 3], [1, 2, 3]
        [2], [2, 3]
        [3]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        vector<int> current;

        subsets(nums, current, ans, -1);

        return ans;
    }
private:
    void subsets(vector<int> &nums, vector<int> &current, vector<vector<int>> &ans, int pos) {
        for(int i = pos + 1; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            ans.push_back(current);

            subsets(nums, current, ans, i);
            current.pop_back();
        }
    }
};

/**
int main() {
    vector<int> nums = {1, 2, 3};

    Solution solution;
    auto ans = solution.subsets(nums);
}
**/