#include <bits/stdc++.h>

using namespace std;

/**
    You are given an m x n grid where each cell can have one of three values:

    - 0 representing an empty cell,
    - 1 representing a fresh orange, or
    - 2 representing a rotten orange.

    Every minute, any fresh orange that is 4-directionally adjacent to a rotten
    orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a
    fresh orange. If this is impossible, return -1.

    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

    Solution:
    BFS
**/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;

        // Add coordinates of rotten oranges to queues
        queue<int> iQueue, jQueue;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    iQueue.push(i);
                    jQueue.push(j);
                }
            }
        }

        // Variable to measure bfs levels
        int countElements = iQueue.size();
        if(countElements != 0) --ans; // Don't count first queue lap

        while(!iQueue.empty()) {
            int i = iQueue.front(); iQueue.pop();
            int j = jQueue.front(); jQueue.pop();

            for(int d = 0; d < 4; ++d) {
                int ii = i + dir[d];
                int jj = j + dir[d + 1];

                if(ii < 0 || jj < 0 || ii >= grid.size() || jj >= grid[0].size() || grid[ii][jj] != 1) continue;

                grid[ii][jj] = 2;
                iQueue.push(ii);
                jQueue.push(jj);
            }

            --countElements;

            // Lap finished
            if(countElements == 0) {
                countElements = iQueue.size();
                ++ans;
            }
        }

        // Check if there are oranges that aren't rotten
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
private:
    int dir[5] = {0, 1, 0, -1, 0};
};