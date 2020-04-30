#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

ll dp[1010][20010];

void solve() {
    ll h, n; cin >> h >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j < 20010; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10010; ++j) {
            dp[i][j + a[i]] = min(dp[i][j + a[i]], dp[i][j] + b[i]);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    ll ans = INF;
        for (int j = h; j < 20010; ++j) {
            ans = min(ans, dp[n][j]);
        }
    cout << ans << endl;
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
