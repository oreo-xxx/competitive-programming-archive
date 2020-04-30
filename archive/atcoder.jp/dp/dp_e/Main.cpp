#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

ll dp[101][100001] = {};

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int n, w; cin >> n >> w;
    vector<int> ws(n);
    vector<int> vs(n);
    ll max_v = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ws[i] >> vs[i];
        max_v += vs[i];
    }

    for (int i = 0; i <= n; ++i) {
        for(int j = 0; j <= max_v; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for(int j = 0; j <= max_v; ++j) {
            if (j - vs[i] >= 0) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - vs[i]] + ws[i]);
            }
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= max_v; ++i) {
        if(dp[n][i] <= w) {
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}