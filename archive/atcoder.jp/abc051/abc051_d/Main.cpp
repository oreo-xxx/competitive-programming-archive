#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

template <typename T>
vector<int> dijkstra(int s,vector< vector< pair<int, T> > > & G){
  using P = pair<T, int>;
  int n=G.size();
  vector<T> ds(n,INF);
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
      T c=e.second;
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return bs;
}

int main() {
  int n, m; cin >>n>> m;
  graph g(n);
  for(int i = 0; i < m; ++i){
    int a, b; ll c;
    cin >>a>> b>> c;
    --a;--b;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  set<pint> used;
  for(int i = 0; i < n; ++i){
    auto bs = dijkstra(i, g);
    for(int i = 0; i < n; ++i){
      if(bs[i]!=-1){
        int l=min(i, bs[i]);
        int r=max(i, bs[i]);
        used.insert({l,r});
      }
    }
  }
  int ans = m-used.size();
  cout << ans << endl;
}
