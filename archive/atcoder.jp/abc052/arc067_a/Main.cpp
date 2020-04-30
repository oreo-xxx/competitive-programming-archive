#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
vector<P> prime_factorize(ll n) {
    vector<P> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    ll ans = 1;
    map<ll, ll> mp;
    for(int i = 2; i <= N; ++i) {
        vector<P> vec = prime_factorize(i);
        for (auto itr : vec) {
            mp[itr.first] += itr.second;
        }
    }
    for(auto itr : mp){
        ans *= (itr.second + 1);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

