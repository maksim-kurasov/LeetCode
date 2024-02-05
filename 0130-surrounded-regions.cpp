#include <bits/stdc++.h>

using namespace std;

/**
    Given an m x n matrix board containing 'X' and 'O', capture all regions that are
    4-directionally surrounded by 'X'.

    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    Explanation: Notice that an 'O' should not be flipped if:
    - It is on the border, or
    - It is adjacent to an 'O' that should not be flipped.
    The bottom 'O' is on the border, so it is not flipped.
    The other three 'O' form a surrounded region, so they are flipped.

    Solution:
    Remember unsurrounded regions, then change every other 'O' except ones we've
    remembered to 'X'
**/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        notFlippable = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));

        for(int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }

        for(int j = 0; j < board[0].size(); ++j) {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(!notFlippable[i][j]) board[i][j] = 'X';
            }
        }
    }
private:
    int dir[5] = {0, 1, 0, -1, 0};
    vector<vector<bool>> notFlippable;

    void dfs(auto& board, int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || notFlippable[i][j])
            return;

        notFlippable[i][j] = true;
        for(int d = 0; d < 4; ++d) {
            dfs(board, i + dir[d], j + dir[d + 1]);
        }
    }
};

int main() {
    vector<vector<char>> array = {{'O', 'O', 'O'},
                                  {'O', 'O', 'O'},
                                  {'O', 'O', 'O'}};

    Solution sol;
    sol.solve(array);
}