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
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll res = 0;
    for (ll r = 0; r <= N/R; ++r) {
        for (ll g = 0; g <= N/G; ++g) {
            if (r * R + g * G > N) continue;
            ll rem = N - r*R - g*G;
            if (rem % B != 0) continue;
            ++res;
        }
    }
    cout << res << endl;
}
