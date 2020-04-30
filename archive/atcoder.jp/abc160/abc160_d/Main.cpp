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

const int CASES = 4;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    // initialization of Floyd-Warshall
    vector<vector<long long> > dp(n, vector<long long>(n, INF64));
    for (int i = 0; i < n; ++i) dp[i][i] = 0;  // necessary

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            dp[i][j] = abs(i-j);
        }
    }

    dp[x-1][y-1] = 1;
    dp[y-1][x-1] = 1;

    // Floyd-Warshall
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = min(dp[i][j], dp[i][x-1] + dp[x-1][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = min(dp[i][j], dp[i][y-1] + dp[y-1][j]);

    map<ll, ll> mp;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            ++mp[dp[i][j]];
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << mp[i]/2 << endl;
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
