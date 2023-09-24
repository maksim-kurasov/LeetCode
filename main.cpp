#include <bits/stdc++.h>
#include "0022-generate-parentheses.cpp"

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define mod 1000000007


using namespace std;

int main() {
    ios

    Solution solution;
    vector<string> ans = solution.generateParenthesis(3);
    for(string &str : ans) cout << str << endl;

    return 0;
}
