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


int main(){
  int n; cin >> n;
  vector<ld> x(n), y(n), s(n),t(n);
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> y[i] >> s[i] >> t[i];
  }
  WeightedGraph G(n);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      ld dx = x[i]-x[j];
      ld dy = y[i]-y[j];
      ld r = sqrt(dx*dx+dy*dy);
      ld v = min(s[i], t[j]);
      G[i].push_back({j,r/v});
    }
  }
  auto d = dijkstra(0,G);
  sort(d.begin(), d.end(), greater<ld>());
  ld ans = 0;
  for(int i = 0; i < n-1; ++i){
    ans = max(ans, d[i]+i);
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
