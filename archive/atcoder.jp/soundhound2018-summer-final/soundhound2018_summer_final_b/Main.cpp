#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int N, K;
vector<long long> b;
// dp[ i ][ (最初が 0 かどうか) ] := i 番目以降についての操作による最大値
long long dp[210000] {};
long long max_[210000] {};

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> K;
    b.resize(N);
    for (int i = 0; i < N; ++i) cin >> b[i];

    dp[0] = 0;
    for (int i = 1; i < K; ++i) {
        dp[i] += dp[i - 1] + b[i - 1];
        max_[i] = max(max_[i - 1], dp[i]);
    }

    for (int i = K; i <= N; ++i) {
        dp[i] = max(dp[i - 1] + b[i - 1], max_[i - K]);
        max_[i] = max(max_[i - 1], dp[i]);
    }
    cout << dp[N] << endl;
    return 0;
}

