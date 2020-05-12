#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll N, M, X; cin >> N >> M >> X;
    vector<ll> c(N);
    vector<vector<ll>> a(N, vector<ll>(M));
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }

    ll ans = INF;
    for(ll bit = 0; bit < (1 << N); ++bit){
        ll tmp = 0;
        vector<ll> score(M);
        for (int i = 0; i < N; ++i) {
            if(bit & (1<<i)){
                tmp += c[i];
                for (int j = 0; j < M; ++j) {
                    score[j] += a[i][j];
                }
            }
        }
        bool f = true;
        for (int i = 0; i < M; ++i) {
            if(score[i] < X) f = false;
        }
        if(f) ans = min(ans, tmp);
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
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
