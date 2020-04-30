#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

ll dp[55][55][10001] = {};

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int w, n, k; cin >> w >> n >> k;
    vector<int> ws(n);
    vector<int> vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> ws[i] >> vs[i];
    }

    for (int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            for(int l = 0; l <= w; ++l) {
                if (l - ws[i] >= 0) {
                    dp[i + 1][j+1][l] = max(dp[i + 1][j + 1][l], dp[i][j][l - ws[i]] + vs[i]);
                }
                dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
            }
        }
    }

    cout << dp[n][k][w] << endl;
    return 0;
}