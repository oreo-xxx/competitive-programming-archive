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
  int n,m; cin >> n >> m;
  Graph G(n);
  vector<int> r(n);
  for(int i = 0; i < n+m-1; ++i){
    int u,v; cin >> u >> v;
    --u;--v;
    G[u].push_back(v);
    ++r[v];
  }
  
  queue<pint> q;
  for(int i = 0; i < n; ++i){
    if(r[i]==0)q.push({i,0});
  }
  vector<pint> dp(n, {-1,0});
  while(!q.empty()){
    pint p = q.front();q.pop();
    int u = p.first ;
    int c = p.second;
    if(dp[u].second > c)continue;
    for(int v : G[u]){
      --r[v];
      if(dp[v].second < c+1){
        dp[v]= {u,c+1};
      }
      if(r[v]==0){
        q.push({v, dp[v].second});
      }
    }
  }
  for(int i = 0; i < n; ++i){
    cout << dp[i].first + 1 << endl;
  }
}
