#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector< vector<ll> > D(N, vector<ll>(N));

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j) {
            cin >> D[i][j];
        }
    }

    vector<vector<ll> > S(N+1, vector<ll>(N+1));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + D[i][j];
        }
    }

    vector<ll> val(N*N+1, 0);
    for (int x1 = 0; x1 < N; ++x1) {
        for (int x2 = x1 + 1; x2 <= N; ++x2) {
            for (int y1 = 0; y1 < N; ++y1) {
                for (int y2 = y1 + 1; y2 <= N; ++y2) {
                    ll area = (x2 - x1) * (y2 - y1);
                    ll sum = S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];
                    val[area] = max(val[area], sum);
                }
            }
        }
    }

    for (int i = 0; i < N*N; ++i) {
        val[i+1] = max(val[i+1], val[i]);
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        ll P; cin >> P;
        cout << val[P] << endl;
    }
}