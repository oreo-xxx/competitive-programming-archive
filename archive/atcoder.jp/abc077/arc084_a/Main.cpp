#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int mid = b[i];

        auto iter_lower = lower_bound(a.begin(), a.end(), mid);
        ll a_num = distance(a.begin(), iter_lower);
        auto iter_upper = upper_bound(c.begin(), c.end(), mid);
        ll c_num = n - distance(c.begin(), iter_upper);

        ans += a_num*c_num;
    }
    cout << ans << endl;
    return 0;
}

