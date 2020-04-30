#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  ll k,n; cin >> k >> n;
  vector<ll> a(n), d(n);
  for(int i = 0; i < n; ++i)cin >> a[i] >> d[i];
  ll lb = 0, ub = INF;
  while (ub-lb>1){
    ll mb = (ub + lb)/2LL;
    ll num = 0;
    for(int i = 0; i < n; ++i){
      if(a[i]>mb)continue;
      num += (mb-a[i])/d[i]+1;
    }
    if(num>=k)ub = mb;
    else lb = mb;
  }
  
  ll ans = 0, num = 0;
  for(int i = 0; i < n; ++i){
    if(a[i]>ub)continue;
    ll t = (ub-a[i])/d[i]+ 1;
    ans += a[i]* t + d[i]*(t*(t-1)/2LL);
    num += t;
  }
  ans -= (num-k)* ub;
  cout << ans << endl;
}
