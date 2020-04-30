#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
 const int MOD = 998244353;

// Lib
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N, A, B, K;
    COMinit();

    cin >> N >> A >> B >> K;
    ll ans = 0;
    for (ll a = 0; a <= N; ++a) { // A の個数を全探索
        ll rem = K - a * A;
        if (rem % B != 0){
            continue;
        }

        ll b = rem / B;
        if (b > N){
            continue;
        }

        ll tmp = COM(N, a) * COM(N, b) % MOD;
        ans += tmp;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
