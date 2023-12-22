#include <bits/stdc++.h>

using namespace std;

/**
    You are given an array of integers stones where stones[i] is the weight of the ith stone.

    We are playing a game with the stones. On each turn, we choose the heaviest two stones
    and smash them together. Suppose the heaviest two stones have weights x and y with x <= y.
    The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

    At the end of the game, there is at most one stone left.
    Return the weight of the last remaining stone. If there are no stones left, return 0.

    Input: stones = [2,7,4,1,8,1]
    Output: 1

    Solution:
    Use priority queue
    Distance = x^2 + y^2 (int)
**/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;

        for(int i = 0; i < points.size(); ++i) {
            queue.push(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
        }

        vector<vector<int>> ans;
        while(k--) {
            int index = queue.top().second;
            queue.pop();
            ans.emplace_back(std::move(points[index]));
        }
    }
};

/**
int main() {

}
**/