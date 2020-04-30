#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll  = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>;
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  ll n,c;cin >> n >> c;
  vector<pll> a(n), b(n);
  vector<pll> suma(n+1),sumb(n+1);
  for(int i = 0; i < n; ++i){
    ll x,v;cin >>x>> v;
    a[i]={x, v};
    suma[i+1].first=a[i].first;
    suma[i+1].second=suma[i].second+a[i].second;
  }
  for(int i = 0; i < n; ++i){
    b[i]={c - a[n-1-i].first, a[n-1-i].second};
    sumb[i+1].first=b[i].first;
    sumb[i+1].second=sumb[i].second+b[i].second;
  }
  
  vector<ll> maxr(n+1), maxl(n+1);
  for(int i = 1; i <= n; ++i){
    ll tmp1 = suma[i].second - 2*suma[i].first;
    maxr[i] = max(maxr[i-1], tmp1);
    ll tmp2 = sumb[i].second - 2*sumb[i].first;
    maxl[i] = max(maxl[i-1], tmp2);
  }
  ll ans = 0;
  for(int r = 0; r <= n; ++r){
    int l = n-r;
    ll dist = suma[r].first;
    ll score = maxl[l] + suma[r].second;
    ll tmp = score - dist;
    ans = max(ans, tmp);
  }
  
  for(int l = 0; l <= n; ++l){
    int r = n-l;
    ll dist = sumb[l].first;
    ll score = maxr[r] + sumb[l].second;
    ll tmp = score - dist;
    ans = max(ans, tmp);
  }
  
  
  cout << ans << endl;
}
