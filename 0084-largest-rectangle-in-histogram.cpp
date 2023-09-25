#include <bits/stdc++.h>

using namespace std;

/*
    Given an array of integers heights representing the histogram's bar height where the width of
    each bar is 1, return the area of the largest rectangle in the histogram.

    Input: heights = [2,1,5,6,2,3]
    Output: 10

    Solution:
    Monotonic increase stack, if current height lower, then extend back, find max area
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;

        heights.push_back(0);

        for(int i = 0; i < heights.size(); ++i) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                maxArea = max(maxArea, (i - st.top().first) * st.top().second);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        return maxArea;
    }
};
