#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
 const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, K; cin >> N >> K;

    vector<ll> a(N), S1(N+1, 0), S2(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        S1[i+1] = S1[i] + a[i];
        S2[i+1] = S2[i] + max(0LL, a[i]);
    }

    ll res = -1 * INF64;
    for (int i = 0; i + K <= N; ++i) {
        int left = i, right = i + K;
        ll k = max(0LL, S1[right] - S1[left]); // K区間を黒にするか白にするか
        ll l = S2[left] - S2[0]; // 左側
        ll r = S2[N] - S2[right]; // 右側
        ll tmp = k + l + r;
        res = max(res, tmp);
    }
    
    cout << res << endl;
    return 0;
}
