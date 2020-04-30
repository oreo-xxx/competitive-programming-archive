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
  ll n,m;ld r,t;
  cin >> n >> m >> r >> t;
  WeightedGraph G(n);
  for(int i = 0; i < m; ++i){
    ll a,b,c;
    cin >> a >> b >> c;
    --a;--b;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
  }
  ld rate = r/t;
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    auto ds = dijkstra(i,G);
    sort(ds.begin(),ds.end());
    for(int j = 1; j < n; ++j){
      ll need = (ll)(ceil( (ld)ds[j]*rate ));
      if(need*(ll)t==ds[j]*(ll)r)++need;
      int idx = lower_bound(ds.begin(),ds.end(),need)-ds.begin();
      if(idx<=j)++idx;
      ans += n-idx;
    }
  }
  cout << ans << endl;
}
