#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int MOD = 1000000007;

double dp[3001][3001] = {};

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int n;
    cin >> n;

    vector<double> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }

    dp[0][0] = 1.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
        }
    }
    double res = 0.0;
    for (int j = (n+1)/2; j <= n; ++j) {
        res += dp[n][j];
    }

    cout << fixed << setprecision(10) << res << endl;

    return 0;
}