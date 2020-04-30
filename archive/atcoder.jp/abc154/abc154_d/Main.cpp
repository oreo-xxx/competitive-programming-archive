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

const int CASES = 3;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ld> a(n), e(n), sum(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        e[i] = (a[i] + 1.0) / 2.0;
    }
    ld ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += e[i];
    }
    ld tmp = ans;
    for (int i = k; i < n; ++i) {
        tmp += e[i];
        tmp -= e[i-k];
        ans = max(ans, tmp);
    }
    cout << fixed << setprecision(10)  << ans << endl;
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
