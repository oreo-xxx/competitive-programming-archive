#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    int N, K;
    ll X[101], Y[101];
    cin >> N >> K;
    for(int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    set<int> xx, yy;
    for(int i = 0; i < N; ++i) xx.insert(X[i]);
    for(int i = 0; i < N; ++i) yy.insert(Y[i]);

    ll ans = -1;
    for(int sx : xx){
        for(int sy : yy){
            for(int tx : xx){
                for(int ty : yy){
                    if (sx <= tx && sy <= ty) {
                        ll area = 1LL * (tx - sx) * (ty - sy);
                        int c = 0;
                        for(int i = 0; i < N; ++i){
                            if (sx <= X[i] && X[i] <= tx && sy <= Y[i] && Y[i] <= ty){
                                c++;
                            }
                        }
                        if (K <= c) {
                            if (ans < 0) ans = area;
                            ans = min(ans, area);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
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

