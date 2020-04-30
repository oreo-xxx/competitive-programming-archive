#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<ll> s(n+1, 0);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    map<ll, ll> mp;
    for (int i = 0; i < n+1; ++i) {
        ++mp[s[i]];
    }

    ll res = 0;
    for (auto it : mp) {
        ll num = it.second;
        res += num * (num - 1) / 2;
    }
    cout << res << endl;

    return 0;

}