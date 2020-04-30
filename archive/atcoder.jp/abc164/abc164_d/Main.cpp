#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


void solve() {
    string s; cin >> s;
    ll n = s.size();
    ll p = 2019;
    vector<ll> a(n), sum(n+1);
    for (ll i = 0; i < n; ++i) {
        ll tmp = (ll)(s[i] - '0');
        a[i] = tmp * modpow(10LL, n-1LL-i, p);
        a[i] %= p;
        sum[i+1] = sum[i] + a[i];
        sum[i+1] %= p;
    }

    ll ans = 0;
    map<ll, ll> mp;
    for(int i = 0; i <= n; ++i){
        ans += mp[sum[i]];
        ++mp[sum[i]];
    }
    cout << ans << endl;
    return;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
