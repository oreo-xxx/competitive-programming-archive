#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int NMAX = 100000;
int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int n; cin >> n;
    int a[n][3] = {};
    int dp[n + 1][3] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }


    int res = 0;
    for (int j = 0; j < 3; ++j) {
        res = max(res, dp[n][j]);
    }
    cout << res << endl;
}