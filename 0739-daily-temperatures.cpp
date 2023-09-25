#include <bits/stdc++.h>

using namespace std;

/*
    Given an array of integers temperatures represents the daily temperatures,
    return an array answer such that answer[i] is the number of days you have to
    wait after the ith day to get a warmer temperature. If there is no future day for
    which this is possible, keep answer[i] == 0 instead.

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

    Solution:
    STACK: [73], 74 -> [74], 75 -> [75], 71 -> [75, 71], 69 -> [75, 71, 69], 72 -> [75, 72], 76 -> [76], 73 -> [76, 73] -> end
    Elements of stack do not currently have the day which temperature is higher. When we encounter such a temperature,
    we update the stack
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};