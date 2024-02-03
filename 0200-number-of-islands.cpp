#include <bits/stdc++.h>

using namespace std;

/**
    Given an m x n 2D binary grid grid which represents a map of '1's
    (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting
    adjacent lands horizontally or vertically. You may assume all
    four edges of the grid are all surrounded by water.

    Input: grid = [
      ["1","1","0","0","0"],
      ["1","1","0","0","0"],
      ["0","0","1","0","0"],
      ["0","0","0","1","1"]
    ]
    Output: 3

    Solution:
    Iterate each pair of [x, y] and dfs from each pair of [x, y] where
    grid[y][x] == '1'. Dfs has to keep track of visited squares (just change
    visited squares to 'V').
**/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if(grid[i][j] != '1')
            return;

        grid[i][j] = 'V';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
