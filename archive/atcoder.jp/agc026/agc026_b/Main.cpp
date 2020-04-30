#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
 const int MOD = 998244353;

// Lib
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
//

ll a, b, c, d;

bool solve() {
    if (a < b) return false;
    if (d < b) return false;
    if (c >= b-1) return true;

    ll g = GCD(b, d);

    // g で割って a%g あまる数で、b 未満の最大の数
    ll max_ = (b - a%g + g-1)/g*g + a%g - g;

    // g で割って a%g あまる数で、c より大きく b 未満な整数があるかどうか
    if (max_ > c) return false;
    else return true;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int T; cin >> T;
    for (int CASE = 0; CASE < T; ++CASE) {
        cin >> a >> b >> c >> d;
        if (solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
