#include <bits/stdc++.h>

using namespace std;

/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
        1. Open brackets must be closed by the same type of brackets.
        2. Open brackets must be closed in the correct order.
        3. Every close bracket has a corresponding open bracket of the same type.

    Example 1:
        Input: s = "()[]{}"
        Output: true
    Example 2:
        Input: s = "(]"
        Output: false

    Use stack and store all parentheses
*/

class Solution {
public:
    bool isValid(string &s) {
        map<char, char> associationMap = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> solutionStack;
        for(char &chr : s) {
            if(!associationMap.contains(chr)) {
                solutionStack.push(chr);
            }
            else {
                if(solutionStack.empty() || solutionStack.top() != associationMap[chr]) return false;
                solutionStack.pop();
            }
        }
        return solutionStack.empty();
    }
};
