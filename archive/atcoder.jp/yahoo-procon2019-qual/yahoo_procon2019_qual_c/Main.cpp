#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ll k, a, b; cin >> k >> a >> b;

    ll ans = 0;

    ll offset = 0;
    if( (k - a - 1) % 2 == 0) offset = 0;
    else offset = 1;

    for(ll i = a - 1; i <= k; i = i + 2){
        ll stock = 1 + i + offset;
        stock += (b - a) * ((k - i - offset) / 2);
        ans = max(ans, stock);
    }

    cout << ans << endl;
    return 0;
}

