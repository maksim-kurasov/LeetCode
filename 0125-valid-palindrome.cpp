#include <bits/stdc++.h>

using namespace std;

/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
    and removing all non-alphanumeric characters, it reads the same forward and backward.
    Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Solution:
    Two pointers, ignore non-alphanumeric symbols, use isalnum function and tolower function
*/

class Solution {
public:
    bool isPalindrome(string &s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            while(!isalnum(s[l]) && l < r) ++l;
            while(!isalnum(s[r]) && l < r) --r;

            if(tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
