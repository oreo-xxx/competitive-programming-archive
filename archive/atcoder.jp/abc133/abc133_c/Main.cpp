#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll L, R; cin >> L >> R;
    if (R - L >= 2019){
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = INF64;
    for (ll i = L; i < R; ++i){
        for (long long j = i + 1; j <= R; ++j){
            ans = min(ans, (i * j) % 2019);
        }
    }
    cout << ans << endl;
    return 0;
}
