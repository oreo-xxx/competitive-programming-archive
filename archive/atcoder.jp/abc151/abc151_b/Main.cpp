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
    ll n, k, m; cin >> n >> k >> m;
    ll a = 0;
    for(int i = 0; i < n-1; ++i){
        ll tmp; cin >> tmp;
        a += tmp;
    }
    ll target = m * n;
    ll diff = target - a;
    ll ans = 0;
    if(diff <= 0){
        ans = 0;
    }
    else if(0 < diff && diff <= k){
        ans = diff;
    }
    else if(k < diff){
        ans = -1;
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
