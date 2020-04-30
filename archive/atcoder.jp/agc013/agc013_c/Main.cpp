#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, L ,T;
    cin >> N >> L >> T;
    vector<int> X(N);
    vector<int> W(N);
    for (int i = 0; i < N; ++i){
        cin >> X[i] >> W[i];
    }

    // ありのT秒後の位置
    // 円周上なのでリングバッファのようにmod
    vector<int> tmp(N);
    for (int i = 0; i < N; ++i) {
        if (W[i] == 1) {
            tmp[i] = (X[i] + T) % L;
        }
        else{
            tmp[i] = ((X[i] - T) % L + L) % L;
        }
    }
    sort(tmp.begin(), tmp.end());

    // 各ありが原点を何周したか数える
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (W[i] == 1){
            count -= (X[i] + T) / L;
        }
        else{
            count -= (X[i] - T - L + 1) / L;
        }
    }
    count = (count % N + N) % N;

    vector<int> ans(N);
    for (int i = 0; i < N; ++i){
        ans[(i + count) % N] = tmp[i];
    }

    for (int i = 0; i < N; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}

