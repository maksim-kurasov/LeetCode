#include <bits/stdc++.h>
#include "0015-3sum.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define mod 1000000007


using namespace std;

int main() {
    ios

    Solution solution;
    vector<int> nums = {-2,0,0,2,2};
    for(auto &s : solution.threeSum(nums))
        cout << s[0] << " " << s[1] << " " << s[2] << endl;

    return 0;
}
