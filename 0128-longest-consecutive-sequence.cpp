#include <bits/stdc++.h>

using namespace std;

/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

    If an element has no left neighbour then it is the start of a sequence, so we start looking for right neighbours
*/

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> consecutiveNums;
        for (int i = 0; i < nums.size(); ++i) {
            consecutiveNums.insert(nums[i]);
        }

        int longest = 0;
        for (int num: consecutiveNums) {
            if (consecutiveNums.contains(num - 1)) continue;

            int current = 0;
            do {
                ++current;
            } while (consecutiveNums.contains(++num));
            longest = max(longest, current);
        }

        return longest;
    }
};