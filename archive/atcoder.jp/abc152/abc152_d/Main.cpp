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

const int CASES = 4;

pint get(ll n){
    string s = to_string(n);
    pint p {s.front() - '0', s.back() - '0'};
    return p;
}

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        pint p = get(i);
        if(p.second==0) continue;
        if(p.first == p.second)++ans;

        for(int j = 1; j <= 6; ++j){
            ll base = pow(10, j) * p.second + p.first;
            ll range = pow(10, j-1);
            ll M = (range-1)* 10 + base;
            //cout << i << ' ' << base << endl;
            if(base > n) break;
            if(M <= n) ans += range;
            else{ // base <= n < M
                //cout << i << ' ' << base <<  ' '<<(n-base)/10 << endl;
                ans += (n - base)/10 + 1;
            }
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
