#include <bits/stdc++.h>

using namespace std;

/*
    Given an integer array nums and an integer k, return the k most frequent elements.

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Bucket sort
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> bucket[nums.size() + 1];
        unordered_map<int, int> counter;

        for(int& num : nums) ++counter[num];

        for(auto& [key, value] : counter) {
            bucket[value].push_back(key);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 0; --i) {
            for(int& elem : bucket[i]) {
                if(ans.size() < k) ans.push_back(elem);
                else return ans;
            }
        }
        return ans;
    }
};