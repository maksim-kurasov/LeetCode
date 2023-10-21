#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    ll k; cin >> k;
    ll sum = 0;
    for(int i = 1; i <= k; ++i) {
        ll a; cin >> a;
        sum += a;
        if(i > 2 && sum < 180 * (i - 2)) {
            cout << -1 << "\n";
            return 0;
        }
    }

    int minVertices = ceil(sum / 180.0) + 2;
    cout << minVertices << " ";

    for(int i = minVertices; i < 10000; ++i) {
        if((double)(180 * (i - 2) - sum) / (i - k) > 179.0) {
            cout << i - 1 << "\n";
            return 0;
        }
    }

    return 0;
}