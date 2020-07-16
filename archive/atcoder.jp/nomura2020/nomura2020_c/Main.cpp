#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 5;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for(int i = 0; i <= n; ++i) cin >> a[i];

    ll now = 1;
    vector<ll> nodes(n+1);
    for(int i = 0; i <= n; ++i){
        nodes[i] = now;
        if(now - a[i] < 0){
            cout << -1 << endl;
            return;
        }
        now -= a[i];
        if(now < INF64) now *= 2LL;
    }

    ll ans = 0;
    now = 0;
    for(int i = n; i >= 0; --i){
        now += a[i];
        if(nodes[i] - now > 0){
            nodes[i] = now;
        }
        ans += nodes[i];
    }

    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
