#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a, b; cin >> a >> b;
    int lo = min(a, b);
    int hi = max(a, b);
    if( (hi+lo) % 2 != 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int ans = (hi + lo) / 2;
    cout << ans << endl;
    return 0;
}
