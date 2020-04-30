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

long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}


ll COM(ll n, ll k){
  ll u= 1,d= 1;
  for(int i = 0; i < k; ++i){
    u *= (n-i);
    u %= MOD;
    d *= (i+1);
    d %= MOD;
  }
  ll ret = u * modinv(d,MOD) % MOD;
  return ret;
}

int main() {
  ll n,k;cin >> n>> k;
  ll tmp = k/n;
  if(tmp!=0){
    ll rem = k%n;
    ll ans = COM(n,rem);
    cout << ans << endl;
  }
  else{
    ll ans = COM(n+k-1,k);
    cout << ans << endl;
  }
}
