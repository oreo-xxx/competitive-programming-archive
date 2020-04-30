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
  ll n; cin >> n;
  vector<pll> l,r;
  for(int i = 0; i < n; ++i){
    ll a,b; cin >> a >> b;
    if(a-b<0){
      l.push_back({a,b});
    }
    else{
      r.push_back({-b,a});
    }
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  ll ans = 0, now = 0;
  for(int i = 0; i < l.size(); ++i){
    ans = max(ans, now +l[i].first);
    now += l[i].first - l[i].second;
  }
  for(int i = 0; i < r.size(); ++i){
    ans = max(ans,now+r[i].second);
    now += r[i].second + r[i].first;
  }
  cout << ans << endl;
}
