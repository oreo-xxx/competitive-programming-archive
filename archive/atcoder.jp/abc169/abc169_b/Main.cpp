#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll N; cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0]==0){
        cout << 0 << endl;
        return;
    }
    ll M = 1e18;
    ll ans = 1;
    for(int i = 0; i < N; ++i){
        ll prev = ans;
        prev *= a[i];
        if(ans > prev){
            cout << -1 << endl;
            return;
        }
        ans = prev;
    }
    if(ans > M || ans < 0){
        cout << -1 << endl;
        return;
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
