#include <bits/stdc++.h>

using namespace std;

/**
    Given a collection of candidate numbers (candidates) and a target number (target),
    find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.

    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output:
        [
        [1,1,6],
        [1,2,5],
        [1,7],
        [2,6]
        ]

    Solution:
    Sort the [candidates] then backtrack (either include either pass)
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(ans, candidates, target, current, 0);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int>& candidates, int target, vector<int> &current, int pos) {
        if(target == 0)
            ans.push_back(current);
        if(target <= 0)
            return;

        for(int i = pos; i < candidates.size(); ++i) {
            if(i != pos && candidates[i] == candidates[i - 1])
                continue;

            current.push_back(candidates[i]);
            backtrack(ans, candidates, target - candidates[i], current, i + 1);
            current.pop_back();
        }
    }
};

/**
int main() {
    vector<int> nums = {10,1,2,7,6,1,5}; // 1 1 2 5 6 7 10, 8

    Solution solution;
    auto ans = solution.combinationSum2(nums, 8);
}
**/