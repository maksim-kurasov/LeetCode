#include <bits/stdc++.h>

using namespace std;

/**
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations
    that the number could represent. Return the answer in any order.

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Solution:
        "23" ->
    Choose every variation of '2' at the first step, choose every variation of '3' at the second one
**/

class Solution {
private:
    map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
public:
    vector<string> letterCombinations(string &digits) {
        if(digits.empty())
            return {};

        vector<string> ans;
        string current;

        backtrack(ans, digits, current, 0);

        return ans;
    }

    void backtrack(vector<string> &ans, string &digits, string &current, int pos) {
        if(pos == digits.length())
            ans.push_back(current);

        for(char chr : mp[digits[pos]]) {
            current += chr;
            backtrack(ans, digits, current, pos + 1);
            current.pop_back();
        }
    }
};

/**
int main() {
    string s = "23";
    Solution solution;
    auto t = solution.letterCombinations(s);
}
**/