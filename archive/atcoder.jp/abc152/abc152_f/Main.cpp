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

WeightedGraph G;

bool rec(int u, int p, int v, bitset<64> &path){
  if(u==v)return true;
  for(auto e : G[u]){
    if(e.first==p)continue;
    if(rec(e.first, u, v, path)){
      path.set(e.second);
      return true;
    }
  }
  return false;
}

int main(){
  int n; cin >> n;
  G.resize(n);
  for(int i = 0; i < n-1; ++i){
    int u,v;cin >> u >> v;
    --u; --v;
    G[u].push_back({v,i});
    G[v].push_back({u,i});
  }
  
  int m; cin >> m;
  vector<int> us(m), vs(m);
  for(int i = 0; i < m; ++i){
    cin >> us[i] >> vs[i];
    --us[i]; --vs[i];
  }
  
  vector<bitset<64>> paths(m);
  for(int i = 0; i < m; ++i){
    rec(us[i], -1, vs[i], paths[i]);
  }
  
  ll ans = 0;
  for(ll i = 0; i < (1LL<<m); ++i){
    bitset<64> val(0), bit(i);
    for(int j = 0; j < m; ++j){
      if(bit[j]) val |= paths[j];
    }
    ll rem = n-1 - val.count();
    ll tmp = (1LL<<rem);
    if(bit.count()%2==0)ans+=tmp;
    else ans -= tmp;
  }
  cout << ans << endl;
}
