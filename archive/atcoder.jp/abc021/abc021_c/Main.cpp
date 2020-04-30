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

vector<ll> dijkstra(int s,vector< vector< pair<int, ll> > > & G){
  using P = pair<ll, int>;
  int n=G.size();
  vector<ll> ds(n,INF);
  //vector<int> bs(n,-1);
  vector<ll> num(n,1);
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
        //bs[u]=v;
        num[u]=num[v];
        pq.emplace(ds[u],u);
      }
      else if(ds[u]==ds[v]+c){
          num[u] += num[v];
          num[u] %= MOD;
      }
    }
  }
  return num;
}

int main() {
	ll  n, a, b, m;cin >>n>> a>> b>> m;
	--a;--b;
	graph G(n);
	for(int i = 0; i < m; ++i){
		ll x,y;cin >>x>> y;
		--x;--y;
		G[x].push_back({y,1});
		G[y].push_back({x,1});
    }
    auto vec = dijkstra(a, G);
    
    cout << vec[b]  << endl;
}
