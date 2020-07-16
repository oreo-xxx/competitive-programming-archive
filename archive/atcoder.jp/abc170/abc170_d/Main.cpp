#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
    int N; cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    vector<bool> used(1000010, true);
    for (int i = 0; i < N; ++i){
        if(used[a[i]]){
            if(a[i] != a[i+1])++ans;
            for(int j = 1; j * a[i] < 1000010; ++j){
                used[j * a[i]] = false;
            }
        }
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
