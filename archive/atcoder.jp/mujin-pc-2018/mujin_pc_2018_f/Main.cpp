#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<char, char>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
const int MOD = 998244353;

// Lib
//

const int MAX = 210000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    COMinit();
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // nums[v] := v 人以上 OK な人数
    vector<ll> nums(N+2, 0);
    for (int i = 0; i < N; ++i) nums[a[i]]++;
    for (int i = N; i >= 0; --i) nums[i] += nums[i+1];

    // DP
    ll dp[N + 2][N + 1] {};
    dp[N+1][0] = 1;
    for (ll x = N; x >= 1; --x) {
        for (ll y = 0; y <= nums[x]; ++y) {
            for (ll k = 0; k <= N; ++k) {
                ll y2 = y - x * k;
                if (y2 < 0) break;
                if (y2 > nums[x+1]) continue;
                ll choose = COM(nums[x] - y2, x * k);
                ll fact = fac[x*k] * modinv(modpow(fac[x], k, MOD), MOD) % MOD * finv[k] % MOD;
                dp[x][y] += dp[x+1][y2] * choose % MOD * fact % MOD;
                dp[x][y] %= MOD;
            }
        }
    }
    cout << dp[1][N] << endl;
    return 0;
}
