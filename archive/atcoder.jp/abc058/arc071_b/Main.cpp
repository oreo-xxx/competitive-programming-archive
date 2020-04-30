#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    ll n, m; cin >> n >> m;
    static vector<ll> x(n), y(m);
    for(int i = 0; i < n; ++i){cin >> x[i];}
    for(int i = 0; i < m; ++i){cin >> y[i];}
    
    ll w = 0, h =0;
    for(int i = 0; i < n-1; ++i){
    	ll nx = (n-1-i)*(i+1) % MOD;
        w += (x[i+1]-x[i]) * nx % MOD;
        w %= MOD;
    }
    w %= MOD;
    for(int i = 0; i < m-1; ++i){
    	ll ny = (m-1-i)*(i+1) % MOD;
        h += (y[i+1]-y[i]) * ny % MOD;
        h %= MOD;
    }
    h %= MOD;
    
    ll ans = w * h % MOD;
    cout << ans << endl;
    return 0;
}
