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

int main() {
    ll N; cin >> N;
    vector<pll> A(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end(), greater<pll>());

    vector<vector<ll>> dp(N+1, vector<ll>(N+1));

    for (ll i = 0; i < N; i++){
        for (ll j = 0; i+j < N; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + abs(A[i+j].first * (A[i+j].second - i)));
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + abs(A[i+j].first * (N-1-j - A[i+j].second)));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= N; i++){
        ans = max(ans, dp[i][N-i]);
    }
    cout << ans << endl;
}

