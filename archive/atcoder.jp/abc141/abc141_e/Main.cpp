#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; string S;
    cin >> N >> S;

    int res = 0;
    int dp[N+1][N+1] {};
    for (int i = N-1; i >= 0; --i) {
        for (int j = N-1; j > i; --j) {
            if (S[i] == S[j]) {
                dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
            }
            res = max(res, min(dp[i][j], j-i));
        }
    }
    cout << res << endl;
    return 0;

}

