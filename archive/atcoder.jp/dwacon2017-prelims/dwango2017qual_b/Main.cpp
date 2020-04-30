#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string S; cin >> S;
    int N = (int)S.size();
    int dp[N + 1][2] {};
    for (int i = N-1; i >= 0; --i) {
        if (S[i] == '2'){
            dp[i][0] = (dp[i][0], dp[i+1][1] + 1);
        }
        else if (S[i] == '5'){
            dp[i][1] = max(dp[i][1], dp[i+1][0] + 1);
        }
        else if (S[i] == '?') {
            dp[i][0] = max(dp[i][0], dp[i+1][1] + 1);
            dp[i][1] = max(dp[i][1], dp[i+1][0] + 1);
        }
    }

    int res = 0;
    for (int i = 0; i < N; ++i) {
        res = max(res, dp[i][0] / 2 * 2);
    }
    cout << res << endl;

}
