#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

ll dp[3001][3001] = {};

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    string s, t; cin >> s >> t;

    dp[0][0] = 0;
    for (int i = 0; i < s.size(); ++i) {
        for(int j = 0; j <= t.size(); ++j) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
        }
    }

    int i = s.size();
    int j = t.size();
    string ans;
    while(i > 0 && j > 0){
        if (dp[i][j] == dp[i-1][j]) {
            --i;
        }
        else if (dp[i][j] == dp[i][j-1]) {
            --j;
        }
        else { // dp[i][j] == dp[i-1][j-1] + 1
            ans = s[i-1] + ans;
            --i, --j;
        }
    }

    cout << ans << endl;

    return 0;
}