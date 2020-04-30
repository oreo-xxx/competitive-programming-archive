#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 2;

void solve() {
    ll n, m; cin >> n >> m;
    // initialization of Floyd-Warshall
    vector<vector<ll> > dp(n, vector<ll>(n, INF64));
    for (int i = 0; i < n; ++i) dp[i][i] = 0;  // necessary

    for (int e = 0; e < m; ++e) {
        int a, b; ll w;
        cin >> a >> b >> w;
        --a;--b;
        dp[a][b] = w;
        dp[b][a] = w;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    int Q; cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        int a, b; ll w;
        cin >> a >> b >> w;
        --a;--b;
        dp[a][b] = min(dp[a][b], w);
        dp[b][a] = min(dp[b][a], w);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][a] + dp[a][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][b] + dp[b][j]);

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += dp[i][j];
            }
        }
        ans /= 2;
        cout << ans << endl;
    }
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
