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

vector<ll> dijkstra(int s,WeightedGraph  & G){
  using P = pair<ll, int>;
  int n=G.size();
  vector<ll> ds(n,INF);
  vector<int> bs(n,-1);
  priority_queue<P, vector<P>, greater<P> > pq;
  ds[s]=0;
  pq.emplace(ds[s],s);
  while(!pq.empty()){
    P p=pq.top();pq.pop();
    int v=p.second;
    if(ds[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      ll c=e.second;
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return ds;
}


int main(){
  int n,m; cin >> n >> m;
  WeightedGraph G(n);
  for(int i = 1; i < n; ++i){
    G[i].push_back({i-1, 0});
  }
  for(int i = 0; i < m; ++i){
    int s,t,c;cin >> s >> t >> c;
    --s; --t;
    G[s].push_back({t,c});
  }
  auto d = dijkstra(0,G);
  ll ans = d[n-1];
  if(ans == INF)ans = -1;
  cout << ans << endl;
}
