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
        // Position + Time
        vector<pair<int, float>> st(position.size());
        for(int i = 0; i < position.size(); ++i) {
            st[i] = {position[i], (target - position[i]) / (float)speed[i]};
        }
        sort(st.begin(), st.end());

        int fleetCount = 0;
        float maxTime = 0.0;
        for(int i = st.size() - 1; i >= 0; --i) {
            float time = st[i].second;
            // If the (i-1)th car has greater time than (i)th car, then (i-1)th car will not catch up to the (i)th one
            if(time > maxTime) {
                ++fleetCount;
                maxTime = st[i].second;
            }
        }
        return fleetCount;
    }
};
