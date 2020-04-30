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
    double W, H, x, y; cin >> W >> H >> x >> y;
    double ans = W * H / 2.0;
    if(2 * x == W && 2 * y == H){
        cout << ans << " " << 1 << endl;
    }
    else{
        cout << ans << " " << 0 << endl;
    }
    return 0;
}
