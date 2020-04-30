#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    int N, M, L; cin >> N >> M >> L;

    // initialization of Floyd-Warshall
    vector<vector<ll> > dp(N, vector<ll>(N, INF64));
    for (int i = 0; i < N; ++i) dp[i][i] = 0;

    // input
    for (int e = 0; e < M; ++e) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        dp[a][b] = c;
        dp[b][a] = c;
    }

    // Floyd-Warshall
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if(dp[i][j] <= L){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = INF64;
            }
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);


    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i){
        int s, t; cin >> s >> t; --s; --t;
        if(dp[s][t] < INF64){
            cout << dp[s][t] -1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    // output
    /*
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp[i][j] < INF64) cout << dp[i][j];
            else cout << "INF";
            if (j != N-1) cout << " ";
        }
        cout << endl;
    }
     */
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

