#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

ll N;
vector<ll> a(3), b(3);
ll dp[30000000];

ll calc(vector<ll> sei, vector<ll> obj, ll M) {
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 3; ++i) {
        for (int v = 0; v + sei[i] <= M; ++v) {
            dp[v+sei[i]] = max(dp[v+sei[i]], dp[v] + obj[i]);
        }
    }

    ll res = M;
    for (int v = 0; v <= M; ++v){
        res = max(res, dp[v] + M-v);
    }
    return res;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) cin >> b[i];

    N = calc(a, b, N);
    N = calc(b, a, N);
    cout << N << endl;
}
