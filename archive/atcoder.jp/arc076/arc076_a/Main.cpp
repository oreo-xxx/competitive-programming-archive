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

ll f(ll n){
  ll ret = 1;
  for(int i = 1; i <= n; ++i){
    ret *= i;
    ret %= MOD;
  }
  return ret % MOD;
}

int main() {
  ll n,m;cin >> n>> m;
  if(n<m){swap(n, m);}
  ll ans= 0;
  if(n-m>1){
    ans= 0;
  }
  else if(n-m==1){
    ans=f(n)*f(m)%MOD;
  }
  else{
    ans=2LL*f(n)*f(n)%MOD;
  }
  cout << ans << endl;
}
