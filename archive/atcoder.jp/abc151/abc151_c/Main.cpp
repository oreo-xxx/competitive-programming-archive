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
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<bool> vec(n, false);
    for (int i = 0; i < m; ++i) {
        int p; string s;
        cin >> p >> s;
        --p;
        if(vec[p]) continue;
        if(s == "AC"){
            vec[p] = true;
        }
        else{
            ++a[p];
        }
    }
    ll ans1 = 0;
    for (int j = 0; j < n; ++j) {
        if(vec[j]) ans1++;
    }
    ll ans2 = 0;
    for (int k = 0; k < n; ++k) {
        if(vec[k]) ans2 += a[k];
    }
    cout << ans1 << ' ' << ans2 << endl;

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
