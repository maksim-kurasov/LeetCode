#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll ans = 0;
        ll n; cin >> n;
        ll prev; cin >> prev;
        for(int i = 1; i < n; ++i) {
            ll a; cin >> a;
            if(prev <= a) {
                prev = a;
                continue;
            }
            ll k = ceil(log2((long double)prev / (long double)a));
            prev = a * pow(2, k);
            ans += k;
        }
        cout << ans << endl;
    }

    return 0;
}