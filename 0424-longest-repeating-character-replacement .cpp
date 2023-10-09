#include <bits/stdc++.h>

using namespace std;

/*
    You are given a string s and an integer k. You can choose any
    character of the string and change it to any other uppercase English character.
    You can perform this operation at most k times.

    Return the length of the longest substring containing the same
    letter you can get after performing the above operations.

    Input: s = "AABABBA", k = 1
    Output: 4

    Solution:
    Sliding window. The answer is the length of the window which is valid (i.e. elements in the window can be replaced
    so that there would be only one type of character remaining). If right pointer encounters a situation when
    the window is no more valid, we increase left pointer.
    Also, it is important to keep track of the most frequent element in the window (maxF)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int counter[26] = {0};

        int l = 0, maxF = 0;
        for(int r = 0; r < s.length(); ++r) {
            ++counter[s.at(r) - 'A'];
            maxF = max(maxF, counter[s.at(r) - 'A']);

            if(r - l + 1 - maxF > k)
                --counter[s.at(l++) - 'A'];

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};