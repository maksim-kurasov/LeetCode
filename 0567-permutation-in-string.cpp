#include <bits/stdc++.h>

using namespace std;

/*
    Given two strings s1 and s2, return true if s2 contains a
    permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations
    is the substring of s2.

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true

    Solution:
    Sliding window. Bucket counter. Window has the size of the first string
*/

class Solution {
public:
    bool equals(const int *arrayA, const int *arrayB) {
        for(int i = 0; i < 26; ++i) {
            if(arrayA[i] != arrayB[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string &s1, string &s2) {
        if(s1.length() > s2.length())
            return false;

        int standart[26] = {0};
        int counter[26] = {0};
        for(int i = 0; i < s1.length(); ++i) {
            ++standart[s1.at(i) - 'a'];
            ++counter[s2.at(i) - 'a'];
        }

        for(int i = s1.length(); i < s2.length(); ++i) {
            if(equals(standart, counter))
                return true;

            ++counter[s2.at(i) - 'a'];
            --counter[s2.at(i - s1.length()) - 'a'];
        }
        return equals(standart, counter);
    }
};