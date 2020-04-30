#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int MAX_N = 10;
const int MAX_W = 110000;
int dp[MAX_N][MAX_W]; // 6 種類だが余裕をもつ

const int CASES = 3;

void solve() {
    int W;
    cin >> W;

    // 品物を列挙 (価値はすべて 1)
    vector<int> weight;
    for (int i = 100; i < 106; i++) weight.push_back(i);
    int n = (int)weight.size();

    // DP初期条件: dp[i][0] = 0
    for (int i = 0; i < MAX_N; ++i) for (int w = 0; w < MAX_W; ++w) dp[i][w] = INF32;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;

    // DPループ
    for (int i = 0; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            dp[i + 1][w] = min(dp[i + 1][w], dp[i][w]);
            if (w >= weight[i]) dp[i + 1][w] = min(dp[i + 1][w], dp[i + 1][w - weight[i]] + 1);
        }
    }
    int ans = 1;
    if(dp[n][W] == INF32){
        ans = 0;
    }
    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}

