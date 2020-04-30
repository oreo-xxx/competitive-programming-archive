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
    string S; cin >> S;
    ll n = S.size();
    ll ans = 0;
    ll num = 0;
    for (ll i = 0; i < n; ++i) {
        if (S[i] == 'W') {
            ans += num;
        }
        else {
            ++num;
        }
    }
    cout << ans << endl;
    return 0;
}
