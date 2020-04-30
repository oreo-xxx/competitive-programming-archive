#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

ll dp[1100][5000];

void solve(){
    int N, M; cin >> N >> M;
    vector<ll> a(M), b(M), c(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        for (int j = 0; j < b[i]; ++j){
            int t; cin >> t; --t;
            // c はビットで表す
            c[i] += (1<<t);
        }
    }

    for (int i = 0; i < 1100; ++i){
        for (int j = 0; j < 5000; ++j){
            dp[i][j] = INF64;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < (1<<N); ++j) {
            // i番目の鍵を使わない
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

            // i番目の鍵を使う
            dp[i+1][j | c[i]] = min(dp[i+1][j | c[i]], dp[i][j] + a[i]);
        }
    }
    ll ans = -1;
    if(dp[M][(1<<N)-1] < INF64){
        ans = dp[M][(1<<N)-1];
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

