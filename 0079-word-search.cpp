#include <bits/stdc++.h>

using namespace std;

/**
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent
    cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true

    Solution:
    [exist]:
        1. Backtrack for every cell on the grid
        2. If the word exist, return TRUE immediately
    [backtrack]:
        1. At each step check if word[i] == board[i][j]
        2. If it reaches i == word.length() then we've found the word
        3. If [i or j are out of borders] or [word[i] != board[i][j]] or [board[i][j] has been traversed], return FALSE
        4. Use board itself as path holder (change traversed cells to '0')
**/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(backtrack(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>> &board, string &word, int i, int j, int pos) {
        if(pos == word.length())
            return true;

        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || word[pos] != board[i][j])
            return false;

        char chr = board[i][j];
        board[i][j] = '0';

        if(backtrack(board, word, i + 1, j, pos + 1)) return true;
        if(backtrack(board, word, i - 1, j, pos + 1)) return true;
        if(backtrack(board, word, i, j + 1, pos + 1)) return true;
        if(backtrack(board, word, i, j - 1, pos + 1)) return true;

        board[i][j] = chr;

        return false;
    }
};

/**
int main() {
    vector<vector<char>> nums = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    Solution solution;
    auto ans = solution.exist(nums, "ABCB");

    cout << ans;
}
**/