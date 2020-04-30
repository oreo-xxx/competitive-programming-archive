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
    vector<int> a(n+1);
    vector<int> b(n);
    ll ans = 0;
    for(int i = 0; i < n + 1; ++i){
        cin >> a[i];
        ans += a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    for(int i = 0; i < n; ++i){
        if(a[i] < b[i]){
            ll res = b[i] - a[i];
            a[i] = 0;
            if(res > a[i+1]){
                a[i+1] = 0;
            }
            else{
                a[i+1] -= res;
            }
        }
        else{
            a[i] -= b[i];
        }
    }
    for(int i = 0; i < n + 1; ++i){
        ans -= a[i];
    }

    cout << ans << endl;
    return 0;
}
