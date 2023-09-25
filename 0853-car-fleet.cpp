#include <bits/stdc++.h>

using namespace std;

/*
    There are n cars going to the same destination along a one-lane road. The destination is target miles away.
    You are given two integer array position and speed, both of length n, where position[i] is the position of the ith
    car and speed[i] is the speed of the ith car (in miles per hour). A car can never pass another car
    ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will
    slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are
    assumed to have the same position).

    A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
    If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

    Return the number of car fleets that will arrive at the destination.

    Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
    Output: 3
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs(position.size());

        // We have to sort these pairs by position, so we create an additional vector
        for(int i = 0; i < position.size(); ++i) {
            pairs[i] = {position[i], speed[i]};
        }
        sort(pairs.begin(), pairs.end());

        // Monotonic Stack
        stack<double> st;
        for(int i = pairs.size() - 1; i >= 0; --i) {
            // Pushing TIME into the stack
            st.push((target - pairs[i].first) / (double)pairs[i].second);
            if(st.size() >= 2) {
                // If the last car is slower than the car that is ahead of it, then we shall keep this car in the stack
                double lastCar = st.top(); st.pop();
                if(lastCar > st.top()) st.push(lastCar);
            }
        }

        // Number of fleets
        return st.size();
    }
};
