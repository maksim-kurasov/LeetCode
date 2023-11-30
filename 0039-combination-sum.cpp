#include <bits/stdc++.h>

using namespace std;

/**
    Given an array of distinct integers candidates and a target integer target,
    return a list of all unique combinations of candidates where the chosen
    numbers sum to target.

    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]

    Solution:
    At each step we either append element to [current] or move to the next element without appending
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        findSums(ans, candidates, cur, 0, target, 0);

        return ans;
    }

    void findSums(vector<vector<int>> &ans, vector<int>& candidates, vector<int> &current, int total, int target, int pos) {
        if(total == target)
            ans.push_back(current);
        if(pos == candidates.size() || total >= target)
            return;

        current.push_back(candidates[pos]);
        findSums(ans, candidates, current, total + candidates[pos], target, pos);
        current.pop_back();
        findSums(ans, candidates, current, total, target, pos + 1);
    }
};

/**
int main() {
    vector<int> nums = {1, 2, 3};

    Solution solution;
    auto ans = solution.subsets(nums);
}
**/