#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll lcm = LCM(c, d);
    ll tmp = b/c + b/d - b/lcm;
    ll tmp2 = (a-1)/c + (a-1)/d - (a-1)/lcm;
    ll ans = (b - a+1) - (tmp - tmp2);
    cout << ans << endl;
    return 0;
}
