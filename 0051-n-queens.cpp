#include <bits/stdc++.h>

using namespace std;

/**
    The n-queens puzzle is the problem of placing n queens on an
    n x n chessboard such that no two queens attack each other.

    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

    Solution:
    Amount of queens = row (1 queen per row)
    In [columns] there are columns that already have queens placed on them
    The same goes for diag1 and diag2
**/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<bool> columns(n, false);
        vector<bool> diag1(n + n - 1, false);
        vector<bool> diag2(n + n - 1, false);

        string s(n, '.');
        vector<string> board(n);
        for(int i = 0; i < n; ++i)
            board[i] = s;

        backtrack(ans, board, 0, n, columns, diag1, diag2);

        return ans;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &board, int i, int n,
                   vector<bool> &columns, vector<bool> &diag1, vector<bool> &diag2) {
        if(i == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; ++j) {
            if(columns[j] || diag1[i + j] || diag2[n - j + i - 1])
                continue;

            board[i][j] = 'Q';
            columns[j] = diag1[i + j] = diag2[n - j + i - 1] = true;
            backtrack(ans, board, i + 1, n, columns, diag1, diag2);
            columns[j] = diag1[i + j] = diag2[n - j + i - 1] = false;
            board[i][j] = '.';
        }
    }
};

int main() {
    int n = 13;
    Solution solution;
    auto t = solution.solveNQueens(n);
}
