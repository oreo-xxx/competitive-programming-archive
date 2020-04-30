#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll n; cin >> n;
    vector<pll> x(n);
    for(int i = 0; i < n; ++i){
        ll c, l;
        cin >> c >> l;
        x[i].first = c + l;
        x[i].second = c - l;
    }
    sort(x.begin(), x.end());
    ll ans = 0;
    ll r = -INF64;
    for (int i = 0; i < n; ++i) {
        if(r <= x[i].second){
            r = x[i].first;
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
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
