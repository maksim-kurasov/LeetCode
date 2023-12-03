#include <bits/stdc++.h>

using namespace std;

/**
    Given a string s, partition s such that every substring of the partition is a palindrome.
    Return all possible palindrome partitioning of s.

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]

    Solution:
            "aab"
            / |  \
           a  aa <aab>
         / |   \
        a <ab> [b]
       /
     [b]

**/

class Solution {
public:
    vector<vector<string>> partition(string &s) {
        vector<vector<string>> ans;
        vector<string> current;

        backtrack(ans, s, current, 0);

        return ans;
    }

    void backtrack(vector<vector<string>> &ans, string &s, vector<string> &current, int pos) {
        if(pos == s.length())
            ans.push_back(current);

        string t;
        for(int i = pos; i < s.length(); ++i) {
            t += s[i];
            if(!isPalindrome(t))
                continue;

            current.push_back(t);
            backtrack(ans, s, current, i + 1);
            current.pop_back();
        }
    }

    bool isPalindrome(const string &s) {
        int l = 0,
            r = s.length() - 1;

        while(l < r)
            if(s[l++] != s[r--])
                return false;

        return true;
    }
};


int main() {
    string s = "abbab";
    Solution solution;
    auto t = solution.partition(s);

}
