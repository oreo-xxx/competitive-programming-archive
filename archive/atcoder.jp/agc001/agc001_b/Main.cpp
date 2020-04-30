#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N, X; cin >> N >> X;
    ll res = N; // 最初の 2 本の合計の長さ

    // 最初の 2 本の平行四辺形
    ll a = max(N - X, X);
    ll b = min(N - X, X); 

    // Euclid の互除法を非再帰で回してみる
    while (b) {
        ll q = a / b;
        ll r = a % b;

        res += (b * 2) * q; // 答えを加算
        if (r == 0) res -= b; // 最後だけ「対角線」のみになるので
        a = b, b = r; // 次の平行四辺形は (b, r)
    }
    cout << res << endl;
}
