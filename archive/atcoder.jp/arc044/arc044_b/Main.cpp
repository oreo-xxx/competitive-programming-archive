#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
	ll n;cin >> n;
	vector<ll> vec(n);
	ll m = 0;
	for(ll i = 0; i < n; ++i){
		ll a;cin >> a;
      if(i==0&&a!=0){
        cout << 0 << endl;
        return 0;
      }
		++vec[a];
		m = max(m, a);
    }
    if(vec[0]!=1){
      cout << 0 << endl;
      return 0;
    }
    ll ans = 1, prev= 1;
    for(ll i = 1; i <= m; ++i){
      ll now = vec[i];
      ll t0= modpow(2LL, prev, MOD)-1;
      ll t1= modpow(t0, now,MOD);
      ll k = (now*(now-1))/2;
      ll t2 = modpow(2LL, k, MOD);
      ll t = t1 * t2 % MOD;
      ans = ans* t % MOD;
      prev= now ;
    }
    cout << ans% MOD << endl;
}
