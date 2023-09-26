#include <bits/stdc++.h>

using namespace std;

/*
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
    find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1]
    and numbers[index2] where 1 <= index1 < index2 < numbers.length.

    !!! Your solution must use only constant extra space.

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]

    Solution:
    Two pointers, if sum < target, then increment left pointer, if sum > target, then decrement right pointer
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> solution(2);

        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum < target)
                ++l;
            else if(sum > target)
                --r;
            else {
                solution[0] = l + 1;
                solution[1] = r + 1;
                break;
            }
        }

        return solution;
    }
};
