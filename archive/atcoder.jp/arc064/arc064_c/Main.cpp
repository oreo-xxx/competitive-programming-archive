#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ld>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

vector<ld> dijkstra(int s,WeightedGraph  & G){
  using P = pair<ld, int>;
  int n=G.size();
  vector<ld> ds(n,INF);
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
      ld c=e.second;
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return ds;
}

ld dist(ld x1, ld y1, ld x2, ld y2){
  return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
  ld sx,sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  int n;
  cin >> n;
  vector<ld> x(n), y(n), r(n);
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> y[i] >> r[i];
  }
  ld m = 0.0;
  WeightedGraph G(n+2);
  ld tmp = dist(sx, sy, gx, gy);
  G[0].push_back({n+1, tmp});
  for(int i = 0; i < n; ++i){
    ld d = dist(sx, sy, x[i], y[i]);
    G[0].push_back({i+1, max(m, d-r[i])});
    
    d = dist(gx, gy, x[i], y[i]);
    G[i+1].push_back({n+1, max(m, d-r[i])});
  }
  for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
      ld d = dist(x[i], y[i], x[j], y[j]);
      G[i+1].push_back({j+1, max(m, d-r[i]-r[j])});
      G[j+1].push_back({i+1, max(m, d-r[i]-r[j])});
    }
  }
  auto v = dijkstra(0, G);
  cout <<fixed << setprecision(10)<<  v[n+1] << endl;
}
