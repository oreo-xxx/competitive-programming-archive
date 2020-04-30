#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
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

ll com(ll n, ll k){
  ll ret = 1;
  for(int i = 0; i < k; ++i){
    ret *= n+k-1-i;
     ret %= MOD;
    ret *= modinv(i+1, MOD);
    ret %= MOD;
  }
  return ret;
}

int main(){
  ll n; cin >> n;
  bool f = false;
  ll w = 0, p = 0, ans = 1;
  
  for(int i = 0; i < n; ++i){
    ll a; cin >> a;
    if(f){
      if(a==-1){
        ++w;
      }
      else{
        ans *= com(a-p+1, w);
        ans %= MOD;
        f = false;
        w = 0;
        p = a;
      }
    }
    else{
      if(a==-1){
        f = true;
        ++w;
      }
      else{
        p = a;
      }
    }
  }
  cout << ans << endl;
}
