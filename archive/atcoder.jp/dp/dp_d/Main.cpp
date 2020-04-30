#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

ll dp[101][1000001] = {};

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int n, w; cin >> n >> w;
    vector<int> ws(n);
    vector<int> vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> ws[i] >> vs[i];
    }

    for (int i = 0; i < n; ++i) {
        for(int j = 0; j <= w; ++j) {
            if (j - ws[i] >= 0) {
                dp[i+1][j] = max(dp[i + 1][j], dp[i][j - ws[i]] + vs[i]);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}