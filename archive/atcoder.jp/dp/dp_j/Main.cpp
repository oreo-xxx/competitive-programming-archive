#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int MOD = 1000000007;

int n;
double dp[301][301][301] = {};

double rec(int i, int j, int k) {
    if (dp[i][j][k] >= 0.0) {
        return dp[i][j][k];
    }

    double res = 0.0;
    if (i > 0) res += rec(i-1, j, k) * i;
    if (j > 0) res += rec(i+1, j-1, k) * j;
    if (k > 0) res += rec(i, j+1, k-1) * k;

    res += n;
    res *= 1.0 / (double)(i + j + k);
    return dp[i][j][k] = res;
}

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    cin >> n;

    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (a == 1) ++one;
        else if (a == 2) ++two;
        else ++three;
    }

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            for(int k = 0; k <= n; ++k){
                dp[i][j][k] = -1.0;
            }
        }
    }

    dp[0][0][0] = 0.0;
    double ans = rec(one, two, three);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}