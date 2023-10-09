#include <bits/stdc++.h>

using namespace std;

/*
    Given n non-negative integers representing an elevation map
    where the width of each bar is 1, compute how much water it can trap after raining.

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6

    Solution:
    Two pointers, calculate maxLeft and maxRight
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int l = 0, r = height.size() - 1;
        // maxLeft - the highest elevation on the left, maxRight - the highest elevation on the right
        int maxLeft = height[l], maxRight = height[r];
        while(l < r) {
            if(maxLeft <= maxRight) {
                // maxLeft <= maxRight -> we can directly add the difference in heights
                maxLeft = max(maxLeft, height[++l]);
                ans += maxLeft - height[l];
            }
            else {
                // maxRight < maxLeft -> we can directly add the difference in heights
                maxRight = max(maxRight, height[--r]);
                ans += maxRight - height[r];
            }
        }

        return ans;
    }
};