#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<int, int>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int MAX = 4040404;

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) cin >> A[i], sum += A[i];
    
    /* ある値が存在するか=部分和問題をin-placeに
    dp[0] = true;
    for(int i = 0; i < N; ++i)
        for(int j = 0, j <= N*A; ++j)
            dp[j + A[i]] |= dp[j]; */

    // 高速化！！！
    // A[i]を加えるパターン(bitをA[i]左にシフト)とORをとることで、
    // A[i]を加えないパターンに対応
    bitset<MAX> dp;
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        // = 加えない || A[i]加算
        dp = (dp | (dp << A[i]));
    }

    /* 全部選ばないのは不適なので2^n-1通り、
    つまり中央値は大きい方半分のうちの最小値
    つまり、(S + 1)/2 以上の値の中での最小値 */
    ll ans;
    for (ans = (sum+1)/2; ans < MAX; ++ans) {
        if (dp[ans]) break;
    }
    cout << ans << endl;
}

