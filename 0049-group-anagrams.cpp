#include <bits/stdc++.h>

using namespace std;

/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    We create Unordered Map where [sorted str is the KEY] and [current group pos in ans array is VALUE]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp;

        for(string& str: strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            if(mp[sortedStr]) {
                ans[mp[sortedStr] - 1].push_back(str);
            }
            else {
                ans.push_back({str});
                mp[sortedStr] = ans.size();
            }
        }

        return ans;
    }
};