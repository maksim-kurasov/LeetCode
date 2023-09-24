#include <bits/stdc++.h>

using namespace std;

/*
    Determine if a 9 x 9 Sudoku board is valid.
    Only the filled cells need to be validated according to the following rules:

    1. Each row must contain the digits 1-9 without repetition.
    2. Each column must contain the digits 1-9 without repetition.
    3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

    Input: board =
        [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
    Output: true

    Check every row, column and square
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Lines
        for(int i = 0; i < board.size(); ++i) {
            int counter[10] = {0};
            for(int j = 0; j < board.size(); ++j) {
                if(board[i][j] == '.') continue;
                if(counter[board[i][j] - '0']++) return false;
            }
        }

        // Rows
        for(int i = 0; i < board.size(); ++i) {
            int counter[10] = {0};
            for(int j = 0; j < board.size(); ++j) {
                if(board[j][i] == '.') continue;
                if(counter[board[j][i] - '0']++) return false;
            }
        }

        // Squares
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++ j) {
                int counter[10] = {0};
                // Square
                for(int s1 = i * 3; s1 < i * 3 + 3; ++s1) {
                    for(int s2 = j * 3; s2 < j * 3 + 3; ++s2) {
                        if(board[s1][s2] == '.') continue;
                        if(counter[board[s1][s2] - '0']++) return false;
                    }
                }
            }
        }

        return true;
    }
};

