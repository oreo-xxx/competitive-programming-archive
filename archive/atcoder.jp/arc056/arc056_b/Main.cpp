#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<pint>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

vector<int> dijkstra(int s, WeightedGraph& G){
  using P = pint;
  int n=G.size();
  vector<int> ds(n,-1);
  priority_queue<P> pq;
  ds[s]=s;
  pq.emplace(ds[s],s);
  while(!pq.empty()){
    P p=pq.top();pq.pop();
    int m= p.first;
    int from=p.second;
    if(ds[from] < m) continue;
    for(auto& e:G[from]){
      int to=e.first;
      if(ds[to]<m){
        ds[to]=m;
        pq.emplace(min(ds[to], to),to);
      }
    }
  }
  return ds;
}

int main() {
	int n,m,s;cin >>n>> m>> s;
	--s;
	WeightedGraph G(n);
	for(int i = 0; i < m; ++i){
		int u,v;cin >>u>> v;
		--u;--v;
		G[u].push_back({v,1});
		G[v].push_back({u,1});
    }
    auto ds = dijkstra(s,G);
    for(int i = 0; i < n; ++i){
      if(ds[i]<i)continue;
      cout << i + 1 << endl;
    }
}
