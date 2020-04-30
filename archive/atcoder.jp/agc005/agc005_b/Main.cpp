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
    int N; cin >> N;

    // place[i]...値iのaにおけるindex
    ll place[N + 1];
    for (int i = 1; i <= N; ++i) {
        ll a; cin >> a;
        place[a] = i;
    }

    ll ans = 0;
    set<ll> used = {0, N + 1};

    for (int i = 1; i <= N; ++i) {
        ll r, l;

        auto itr = used.lower_bound(place[i]);
        r = *itr;
        l = *(--itr);
        ans += i * (place[i] - l) * (r - place[i]);
        used.insert(place[i]);
    }

    cout << ans << endl;
    return 0;
}
