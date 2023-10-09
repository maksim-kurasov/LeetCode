#include <bits/stdc++.h>

using namespace std;

/*
    You are given an m x n integer matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Solution:
    Consider the matrix 1d array and binary search it
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
            columns = matrix[0].size();

        int l = 0,
            r = rows * columns - 1,
            c = 0;
        int row, column;
        while(l <= r) {
            c = (l + r) / 2;
            row = c / columns;
            column = c % columns;

            if(target == matrix[row][column])
                return true;

            else if(target > matrix[row][column])
                l = c + 1;
            else
                r = c - 1;
        }
        return false;
    }
};