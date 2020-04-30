#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    ll g = GCD(a, b);
    return a / g * b;
}
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<ll> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    ll ans = T[0];
    for (int i = 1; i < N; ++i) {
        ans = LCM(ans, T[i]);
    }

    cout << ans << endl;

    return 0;
}

