#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 1;

void solve(){
    int H, W, K;
    cin >> H >> W >> K;
    --K;
    ll dp[H + 1][W + 1] = {};
    dp[0][0] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int bit = 0; bit < 1<<(W-1); ++bit) {
                bool ok = true;
                for (int k = 0; k < W-2; ++k) {
                    if ((bit & (1<<k)) && (bit & (1<<(k+1)))){
                        ok = false;
                    }
                }

                if (!ok) continue;
                int nj = j;
                if (bit & (1<<j)) nj = j+1;
                else if (j > 0 && (bit & (1<<(j-1)))) nj = j-1;
                dp[i+1][nj] += dp[i][j];
                dp[i+1][nj] %= MOD;
            }
        }
    }
    cout << dp[H][K] << '\n';

    return;
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

