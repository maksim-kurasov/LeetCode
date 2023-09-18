#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> setNums;
        for(int num : nums) {
            setNums.insert(num);
        }
        return nums.size() != setNums.size();
    }
};

