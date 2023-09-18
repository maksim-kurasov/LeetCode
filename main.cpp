#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define mod 1000000007


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

int main() {
    ios

    Solution solution;
    vector<int> nums = {1,2,3,1};

    cout << solution.containsDuplicate(nums) << endl;

    return 0;
}
