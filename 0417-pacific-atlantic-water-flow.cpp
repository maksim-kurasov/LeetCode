#include <bits/stdc++.h>

using namespace std;

/**
    There is an m x n rectangular island that borders both the Pacific Ocean
    and Atlantic Ocean. The Pacific Ocean touches the island's left and top
    edges, and the Atlantic Ocean touches the island's right and bottom edges.

    The island is partitioned into a grid of square cells. You are given
    an m x n integer matrix heights where heights[r][c] represents the
    height above sea level of the cell at coordinate (r, c).

    The island receives a lot of rain, and the rain water can flow to
    neighboring cells directly north, south, east, and west if the
    neighboring cell's height is less than or equal to the current
    cell's height. Water can flow from any cell adjacent to an ocean
    into the ocean.

    Return a 2D list of grid coordinates result where result[i] = [ri, ci]
    denotes that rain water can flow from cell (ri, ci) to both the Pacific
    and Atlantic oceans.

    Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

    Solution:
    We first find out from what squares can we get to Pacific Ocean. Then we
    do the same for Atlantic Ocean.

    Notice, that northern and western edges of the matrix can flawlessly
    flow into Pacific Ocean. Eastern and southern edges - into Atlantic Ocean.
    Use this fact to dfs the matrix (if square {x, y} can flow into square {x1, y1},
    and {x1, y1} is an edge, then {x, y} can flow into the same ocean {x1, y1} can)
**/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int N = heights.size();
        int M = heights[0].size();

        vector<vector<bool>> pacificOcean(N, vector<bool>(M, false));
        vector<vector<bool>> atlanticOcean(N, vector<bool>(M, false));

        for(int i = 0; i < N; ++i) {
            dfs(heights, pacificOcean, i, 0, -1);
            dfs(heights, atlanticOcean, i, M - 1, -1);
        }

        for(int j = 0; j < M; ++j) {
            dfs(heights, pacificOcean, 0, j, -1);
            dfs(heights, atlanticOcean, N - 1, j, -1);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(pacificOcean[i][j] and atlanticOcean[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
private:
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};

    void dfs(auto& heights, auto& ocean, int i, int j, int prev) {
        if(i < 0 or j < 0 or i >= heights.size() or j >= heights[0].size() or prev > heights[i][j] or ocean[i][j])
            return;

        ocean[i][j] = true;
        for(int k = 0; k < 4; ++k) {
            dfs(heights, ocean, i + di[k], j + dj[k], heights[i][j]);
        }
    }
};
