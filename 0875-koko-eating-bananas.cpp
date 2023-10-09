#include <bits/stdc++.h>

using namespace std;

/*
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
    The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile
    of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats
    all of them instead and will not eat any more bananas during this hour.

    Return the minimum integer k such that she can eat all the bananas within h hours.

    Input: piles = [3,6,7,11], h = 8
    Output: 4

    Solution:
    k definitely lays in range [1, maxPile], so we can binary search that range
*/

class Solution {
public:
    bool canEat(vector<int> &piles, int speed, int h) {
        int time = 0;

        for(int pile : piles) {
            time += (pile - 1) / speed + 1;
            if(time > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long minSpeed = 1,
                  maxSpeed = *max_element(piles.begin(), piles.end());

        long long avSpeed;
        while(minSpeed <= maxSpeed) {
            avSpeed = (minSpeed + maxSpeed) / 2;

            if(canEat(piles, avSpeed, h))
                maxSpeed = avSpeed - 1;
            else
                minSpeed = avSpeed + 1;

        }

        return minSpeed;
    }
};