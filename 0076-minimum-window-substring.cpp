#include <bits/stdc++.h>

using namespace std;

/*
    Given two strings s and t of lengths m and n respectively,
    return the minimum window substring of s such that every
    character in t (including duplicates) is included in the window.
    If there is no such substring, return the empty string "".

    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"

    Solution:
    Sliding window. First, find the window that contains all needed elements,
    then move the window, so that it still contains the elements
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int ansL = 0, ansR = INT_MAX;

        int counterT[128] = {0};
        for(const char chr : t)
            ++counterT[chr];

        int counterS[128] = {0};
        int matches = 0;
        queue<int> positions;
        for(int r = 0; r < s.length(); ++r) {
            // Ignore needless elements
            if(counterT[s.at(r)] == 0)
                continue;

            // Update Positions
            positions.push(r);

            // Update Counter
            ++counterS[s.at(r)];
            if(counterS[s.at(r)] <= counterT[s.at(r)])
                ++matches; // Update Matches

            if(matches == t.length()) {
                // Delete excess elements
                while(counterS[s.at(positions.front())] > counterT[s.at(positions.front())]) {
                    --counterS[s.at(positions.front())];
                    positions.pop();
                }
                // Update Ans
                if (ansR - ansL > positions.back() - positions.front()) {
                    ansL = positions.front();
                    ansR = positions.back();
                }
            }
        }

        return (ansL == 0 && ansR == INT_MAX) ? "" : s.substr(ansL, ansR - ansL + 1);
    }
};