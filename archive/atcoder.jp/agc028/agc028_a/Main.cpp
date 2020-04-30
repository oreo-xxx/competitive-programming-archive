#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
ll GCD(ll n, ll m) {
    return m ? GCD(m, n % m) : n;
}
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    ll g = GCD(n, m);

    bool flag = true;
    for (ll i = 0; i < g; ++i) {
        if (s[i * n / g] != t[i * m / g]){
            flag = false;
            break;
        }
    }

    ll res = n / g * m;
    if (flag == false){
        res = -1;
    }
    cout << res << endl;

    return 0;
}
