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

unordered_map<int, int> prime_factorize(int n) {
    unordered_map<int, int> res;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res[p] = num;
    }
    if (n != 1) res[n] = 1;
    return res;
}

void solve() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<unordered_map<int, int> > p;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        p.emplace_back(prime_factorize(a));
    }
    for(auto& pi : p){
        for(auto& it : pi){
            if(mp.count(it.first) != 0){
                mp[it.first] = max(mp[it.first], it.second);
            }
            else{
                mp[it.first] = it.second;
            }
        }
    }

    ll ans = 0;
    for(auto& pi : p){
        ll tmp = 1;
        for (auto& it : mp) {
            if(pi.count(it.first) != 0){
                tmp *= modpow(it.first, it.second - pi[ it.first ], MOD);
            }
            else{
                tmp *= modpow(it.first, it.second, MOD);
            }
            tmp %= MOD;
        }
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
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
