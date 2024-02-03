#include <bits/stdc++.h>

using namespace std;

/**
    You are given an m x n binary matrix grid. An island is a group of
    1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    The area of an island is the number of cells with a value 1 in the island.

    Return the maximum area of an island in grid. If there is no island,
    return 0.

    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
                    [0,0,0,0,0,0,0,1,1,1,0,0,0],
                    [0,1,1,0,1,0,0,0,0,0,0,0,0],
                    [0,1,0,0,1,1,0,0,1,0,1,0,0],
                    [0,1,0,0,1,1,0,0,1,1,1,0,0],
                    [0,0,0,0,0,0,0,0,0,0,1,0,0],
                    [0,0,0,0,0,0,0,1,1,1,0,0,0],
                    [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be
    connected 4-directionally.

    Solution:
    Dfs each square where grid[i][j] == 1, keep track of visited squares
    Dfs should return the area of the island
**/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
    }
private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if(grid[i][j] != 1)
            return 0;

        grid[i][j] = -1;
        return 1 + dfs(grid, i + 1, j) +
                dfs(grid, i - 1, j) +
                dfs(grid, i, j + 1) +
                dfs(grid, i, j - 1);
    }
};
