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

Graph G;

void dfs(int u, ll s, vector<int>& vec){
  vec[u]=s;
  for(auto& e : G[u]){
    if(vec[e]!=-1)continue;
    dfs(e, s+1, vec);
  }
}

int main(){
  int n,u,v;cin >> n >> u >> v;
  --u;--v;
  G.resize(n);
  for(int i = 0; i < n-1; ++i){
    int s,t;cin >> s >> t;
    --s;--t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  vector<int> a(n,-1),t(n,-1);
  dfs(u,0,t);
  dfs(v,0,a);
  
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    if(G[i].size()!=1)continue;
    if(a[i]>t[i] && a[i]>ans) ans = a[i];
  }
  cout << ans-1 << endl;
}
