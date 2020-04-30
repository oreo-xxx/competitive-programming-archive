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

void dec(map<long long, long long, greater<ll>> &ma, long long a) {
    ma[a]--;
    if (ma[a] == 0) {
        ma.erase(a);
    }
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    map<ll, ll, greater<ll> > ma;
    for (int i = 0; i < N; ++i) ma[a[i]]++;

    ll ans = 0;
    for (int i = 0; i < N && !ma.empty(); ++i) {
        ll val = ma.begin()->first;
        dec(ma, val);
        ll po = 1;
        while (po <= val) po *= 2;
        ll rem = po - val;
        if (ma.count(rem)) {
            ++ans;
            dec(ma, rem);
        }
    }
    cout << ans << endl;
    return 0;
}
