#include <bits/stdc++.h>

using namespace std;

/*
    You are given an integer array height of length n. There are n vertical lines drawn
    such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49

    Solution:
    Two pointers, if next height is greater than the current one, then increase the pointer
*/

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int l = 0, r = heights.size() - 1;
        while(l < r) {
            area = max(area, min(heights[l], heights[r]) * (r - l));
            if(heights[l] < heights[r])
                ++l;
            else
                --r;
        }

        return area;
    }
};