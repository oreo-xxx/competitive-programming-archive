#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n; cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; ++i){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int l = d[n/2 - 1];
    int r = d[n/2];
    int ans = r-l;
    cout << ans << endl;
    return 0;
}
