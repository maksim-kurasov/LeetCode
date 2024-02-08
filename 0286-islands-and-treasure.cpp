#include <bits/stdc++.h>

using namespace std;

/**
    You are given a m×n 2D grid initialized with these three possible values:

    1. -1 - A water cell that can not be traversed.
    2. 0 - A treasure chest.
    3. INF - A land cell that can be traversed. We use the integer 2^31 - 1 =
       2147483647 to represent INF.

    Fill each land cell with the distance to its nearest treasure chest.
    If a land cell cannot reach a treasure chest than the value should remain INF.

    Assume the grid can only be traversed up, down, left, or right.

    Input: [
      [2147483647,-1,0,2147483647],
      [2147483647,2147483647,2147483647,-1],
      [2147483647,-1,2147483647,-1],
      [0,-1,2147483647,2147483647]
    ]

    Output: [
      [3,-1,0,1],
      [2,2,1,-1],
      [1,-1,2,-1],
      [0,-1,3,4]
    ]

    Solution:
    BFS from treasure chests
**/

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<int> iQueue, jQueue;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 0) {
                    iQueue.push(i);
                    jQueue.push(j);
                    visited[i][j] = true;
                }
            }
        }

        int distance = 0;
        int elemCount = iQueue.size();

        while(!iQueue.empty()) {
            int i = iQueue.front(); iQueue.pop();
            int j = jQueue.front(); jQueue.pop();

            grid[i][j] = distance;

            for(int d = 0; d < 4; ++d) {
                int ii = i + dir[d];
                int jj = j + dir[d + 1];

                if(ii < 0 || jj < 0 || ii >= grid.size() || jj >= grid[0].size() || visited[ii][jj] || grid[ii][jj] == -1) continue;

                iQueue.push(ii);
                jQueue.push(jj);
                visited[ii][jj] = true;
            }

            --elemCount;
            if(elemCount == 0) {
                elemCount = iQueue.size();
                ++distance;
            }
        }
    }
private:
    int dir[5] = {0, 1, 0, -1, 0};
};