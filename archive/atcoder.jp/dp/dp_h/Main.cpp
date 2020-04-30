#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int MOD = 1000000007;

ll dp[1001][1001] = {};

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for(int i = 0; i < h; ++i){
        cin >> a[i];
    }

    dp[0][0] = 1;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i + 1 < h && a[i + 1][j] == '.'){
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            if (j + 1 < w && a[i][j + 1] == '.') {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;

    return 0;
}