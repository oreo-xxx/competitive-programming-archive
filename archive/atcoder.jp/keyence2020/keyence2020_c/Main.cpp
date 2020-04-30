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
    ll n, k, s; cin >> n >> k >> s;
    vector<ll> a(n);
    ll M = pow(10, 9);
    for (int i = 0; i < k; ++i) {
        a[i] = s;
    }
    for (int i = k; i < n; ++i) {
        if(s != M) a[i] = s+1;
        else a[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if(i == n-1) cout << endl;
        else cout << ' ';
    }
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
