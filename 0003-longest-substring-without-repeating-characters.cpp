#include <bits/stdc++.h>

using namespace std;

/*
    Given a string s, find the length of the longest substring
    without repeating characters.

    Input: s = "abcabcbb"
    Output: 3

    Solution:
    Bucket counter, when encounter repeated char nullify currentLength and update maxLength
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, currentLength = 0;
        vector<int_fast16_t> counter(256, -1);
        for(int i = 0; i < s.length(); ++i) {
            int_fast16_t index = s.at(i);
            if(counter[index] > -1 && counter[index] >= i - currentLength) {
                maxLength = max(maxLength, currentLength);
                currentLength = i - counter[index];
            }
            else
                ++currentLength;
            counter[index] = i;
        }
        return max(maxLength, currentLength);
    }
};