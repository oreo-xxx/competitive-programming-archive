#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll x, y; cin >> x >> y;
    ll res = 1LL<<60;

    if (x <= y) res = min(res, y-x);
    if (-x <= y) res = min(res, y+x+1);
    if (x <= -y) res = min(res, -y-x+1);
    if (-x <= -y) res = min(res, -y+x+2);

    cout << res << endl;
    return 0;
}
