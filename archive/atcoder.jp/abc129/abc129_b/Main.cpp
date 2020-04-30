#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n;cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }

    vector<ll> sum(n+1);
    for(int i = 0; i < n; ++i){
        sum[i+1] += (sum[i] + w[i]);
    }

    ll ans = INF64;
    for(int i = 1; i <= n; ++i){
        ll left = sum[i];
        ll right = sum[n] - sum[i];
        ans = min(ans, abs(right-left));
    }
    cout << ans << endl;
    return 0;
}

