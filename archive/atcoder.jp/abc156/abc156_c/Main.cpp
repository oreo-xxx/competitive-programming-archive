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

const int CASES = 2;

void solve() {
    ll N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    ll ans = INF64;
    for (int i = 0; i <= 100; ++i) {
        ll tmp = 0;
        for (int j = 0; j < N; ++j) {
            tmp += (A[j]-i)*(A[j]-i);
        }
        ans = min(ans, tmp);
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
