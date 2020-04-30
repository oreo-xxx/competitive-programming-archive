#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//
ll calc(ll N) {
    ll ret = 0;
    while (N > 0) {
        ret += N % 10;
        N /= 10;
    }
    return ret;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N; cin >> N;
    long long ans = INF64;
    for (ll i = 1; i < N; ++i) {
        ll j = N - i;
        ll tmp = calc(i) + calc(j);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
