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
vector<T> dijkstra(int s,vector< vector< pair<int, T> > > & G){
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
  return ds;
}

int main() {
	int n,m; ll T; cin >> n>> m>> T;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)cin >>a[i];
	static graph G(n);
	static graph rG(n);
	for(int i = 0; i < m; ++i){
		int f, t; ll c; cin >>f>> t>> c;
		--f;--t;
		G[f].push_back({t,c});
		rG[t].push_back({f,c});
    }
    auto d = dijkstra(0, G);
    auto d2=dijkstra(0,rG);
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(d[i]==INF|| d2[i]==INF){continue;}
        ans = max(ans, a[i]*(T-d[i]-d2[i]));
    }
    cout << ans << endl;
}
