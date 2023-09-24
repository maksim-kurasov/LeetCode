#include <bits/stdc++.h>

using namespace std;

/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    typically using all the original letters exactly once.

    Input: s = "anagram", t = "nagaram"
    Output: true

    Count the characters in both strings using array then iterate array and check
    if the amounts of characters in the strings were equal
*/

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        if(s.size() != t.size()) return false;

        uint_fast16_t seen[26] = {0};
        for(int i = 0; i < s.length(); ++i) {
            ++seen[s[i] - 'a'];
            --seen[t[i] - 'a'];
        }
        for(uint_fast16_t& num : seen) {
            if(num != 0) return false;
        }
        return true;
    }
};