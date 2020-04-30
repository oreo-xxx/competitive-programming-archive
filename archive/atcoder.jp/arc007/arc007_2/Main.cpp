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
    int tmp = 0;
    vector<int> a(n+1);
    for (int i = 0; i < n+1; ++i) {
        a[i] = i;
    }
    for(int i = 0; i < m; ++i){
        int b; cin >> b;
        int idx = 0;
        for(idx = 0; idx < n + 1; ++idx){
            if(a[idx] == b){
                break;
            }
        }
        swap(a[0], a[idx]);
    }
    for(int i = 1; i < n+1; ++i){
        cout << a[i] << endl;
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
