#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//
uint64_t dp[101010][13]; // mod13

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string s; cin >> s;
    int n = s.length();

    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        int c;
        if (s[i] == '?') c = -1;
        else c = s[i] - '0';

        for (int j = 0; j < 10; j++) {
            if (c != -1 && c != j) continue;
            for (int ki = 0; ki < 13; ki++) {
                dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
            }
        }

        for (int j = 0; j < 13; j++){
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[n][5] << endl;
    return 0;    return 0;
}
