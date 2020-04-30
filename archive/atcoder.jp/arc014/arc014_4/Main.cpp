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

int main(){
  ll all,n,m;
  cin >> all >> n >> m;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  ll h = a[0]-1;
  ll t = all -a[n-1];
  vector<ll> d(n-1),sum(n);
  for(int i = 0; i < n-1; ++i){
    d[i]=a[i+1]-a[i]-1;
  }
  sort(d.begin(),d.end());
  for(int i = 0; i < n-1; ++i){
    sum[i+1]=sum[i]+d[i];
  }
  for(int i = 0; i < m; ++i){
    ll x,y;cin >> x >> y;
    ll ans = all;
    ans -= max(h-x,0LL);
    ans -= max(t-y,0LL);
    int idx=lower_bound(d.begin(),d.end(),x+y)-d.begin();
    ans-= sum[n-1]-sum[idx]-(n-1-idx)*(x+y);
    cout << ans << endl;
  }
}
