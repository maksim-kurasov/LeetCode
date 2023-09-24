#include <bits/stdc++.h>

using namespace std;

/*
    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
    Evaluate the expression. Return an integer that represents the value of the expression.

    Note that:
        - The valid operators are '+', '-', '*', and '/'.
        - Each operand may be an integer or another expression.
        - The division between two integers always truncates toward zero.
        - There will not be any division by zero.
        - The input represents a valid arithmetic expression in a reverse polish notation.
        - The answer and all the intermediate calculations can be represented in a 32-bit integer.

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9

    Solution:
    STACK. When we encounter operation sign we retrieve two top numbers from stack and perform the operation on them.
    When we encounter a number we push the number into the stack
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int last;

        for(string &token : tokens) {
            if(token == "+") {
                last = st.top();
                st.pop();
                st.top() += last;
            }
            else if(token == "-") {
                last = st.top();
                st.pop();
                st.top() -= last;
            }
            else if(token == "*") {
                last = st.top();
                st.pop();
                st.top() *= last;
            }
            else if(token == "/") {
                last = st.top();
                st.pop();
                st.top() /= last;
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};