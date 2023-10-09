#include <bits/stdc++.h>

using namespace std;

/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a
    different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Input: prices = [7,1,5,3,6,4]
    Output: 5

    Solution:
    Two pointers, if left > right then left = right
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int l = 0, r = 1;
        while(r < prices.size()) {
            if(prices[l] > prices[r])
                l = r;
            ans = max(ans, prices[r++] - prices[l]);
        }
        return ans;
    }
};