#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, k; cin >> n >> k;

    priority_queue<P, vector<P>, greater<P> > que;
    for(int i = 0; i < n; ++i){
        ll a, b; cin >> a >> b;
        que.push({a, b});
    }

    ll ans = 0;
    for(int i = 0; i < k; ++i){
        P p = que.top(); que.pop();
        ans += p.first;
        que.push({p.first + p.second, p.second});
    }
    cout << ans << endl;

    return 0;
}

