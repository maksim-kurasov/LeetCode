#include <bits/stdc++.h>

using namespace std;

/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

    Solution:
    There are 3 scenarios:
        1. The amount of opened parentheses equals the amount of closed ones
                -> we can only add opened parentheses
        2. The amount of closed parentheses is less than the amount of opened ones AND
           the amount of opened parentheses equals n
                -> we can only add closed parentheses
        3. The amount of closed parentheses is less than the amount of opened ones AND
           the amount of opened parentheses is less than n
                -> we can add either opened or closed parentheses
*/

class Solution {
public:
    void rec(string str, int opened, int closed, int n, vector<string> &ans) {
        if(opened == closed && opened == n) {
            return ans.push_back(str);
        }

        if(opened < n) {
            rec(str + "(", opened + 1, closed, n, ans);
        }
        if(closed < opened) {
            rec(str + ")", opened, closed + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec("(", 1, 0, n, ans);
        return ans;
    }
};