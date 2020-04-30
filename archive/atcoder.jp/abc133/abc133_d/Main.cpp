#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        A[i] *= 2;
    }

    // x0 = 0 のとき
    ll offset = 0;
    for (int i = 0; i < N; ++i){
        offset = A[i] - offset;
    }
    ll x = offset / 2;

    // 復元
    ll cur = x;
    for (int i = 0; i < N; ++i) {
        cout << cur << " ";
        cur = A[i] - cur;
    }
    cout << endl;
    return 0;
}
