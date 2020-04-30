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
void add(ll &a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; ++i) cin >> c[i];

    vector<int> places[210000];
    ll dp[210000];

    // places[i] := (c[j] = i となるような j の集まり)
    for (int i = 0; i < N; ++i) places[c[i]].push_back(i);

    // DP
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        // 特に操作しない場合
        add(dp[i], dp[i-1]);

        // 操作する場合
        int color = c[i-1];
        // c[i] が color 色の何番目の要素か
        int it = lower_bound(places[color].begin(), places[color].end(), i-1) - places[color].begin();
        if (it > 0) {
            int j = places[color][it - 1]; // c[j] = c[i] となる j
            if ((i-1) - j > 1){
                add(dp[i], dp[j+1]);
            }
        }
    }
    cout << dp[N] << endl;
}
