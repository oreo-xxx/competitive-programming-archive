#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    ll ans = p[n - 1] / 2;
    for(int i = 0; i < n - 1; ++i){
        ans += p[i];
    }

    cout << ans << endl;
    return 0;
}
