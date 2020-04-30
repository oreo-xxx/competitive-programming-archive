#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
ll R, B;
ll x, y;

bool check(ll mb){
    // 領域
    // y1 = -1 * (r - 1) * x1 + (R - mb);
    // y2 = -1 * (b - 1) * x2 + (B - mb);
    // x1 + x2 = mb, y1 >= 0 , y2 >= 0
    //
    // mb = (R-mb)/(r-1) + (B-mb)/(b-1)
    if( ((R - mb)/(x - 1) + (B - mb)/(y - 1)) >= mb){
        return true;
    }
    return false;
}
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> R >> B >> x >> y;

    ll lb = 0, ub = 2 * min(R, B);
    while(ub - lb > 1){
        ll mb = (lb + ub) / 2;
        if(check(mb)){
            lb = mb;
        }else{
            ub = mb;
        }
    }

    cout << lb << endl;
    return 0;
}

