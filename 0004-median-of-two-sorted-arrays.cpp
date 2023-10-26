#include <bits/stdc++.h>

using namespace std;

/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively,
    return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)).

    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000

    Solution:

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),
            n2 = nums2.size();

        int l = 0,
            r = n1 - 1;
        while(l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = (n2 - mid1);

            if(nums1[mid1] <= nums2[mid2 + 1] && nums2[mid2] <= nums1[mid1 + 1]) {
                if((n1 + n2) % 2 == 0)
                    return (max(nums1[mid1], nums2[mid2]) + min(nums1[mid1 + 1], nums2[mid2 + 1])) / 2.0;
                else
                    return 0;
            }

        }

    }
};