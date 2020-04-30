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

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N; cin >> N;
    ll ans = 0;
    for (ll r = 1; r*r <= N; ++r) {
        if ((N-r) % r == 0 && (N-r)/r > r){
            ans += (N-r)/r;
        }
    }
    cout << ans << '\n';
    return 0;
}
