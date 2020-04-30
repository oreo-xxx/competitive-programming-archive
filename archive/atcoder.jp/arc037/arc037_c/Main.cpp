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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll l = 0, r = INF64;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            // ai * bj <= mid  bj <= mid / ai
            // bの中で、k / ai　以下である個数を足す
            cnt += upper_bound(b.begin(), b.end(), mid / a[i]) - b.begin();
        }
        if(cnt < k){
            l = mid;
        }else{
            r = mid;
        }
    }

    for (ll pos = l; pos <= r; ++pos)
    {
        ll cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cnt += upper_bound(b.begin(), b.end(), pos / a[i]) - b.begin();
        }
        if(k <= cnt){
            cout << pos << endl;
            return 0;
        }
    }

    return 0;
}
