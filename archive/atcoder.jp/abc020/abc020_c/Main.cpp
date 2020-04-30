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

vector<ll> dijkstra(int s,WeightedGraph& G, ll mb){
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
      if(c==-1) c = mb;
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
  ll h,w,t;cin >> h >> w >> t;
  WeightedGraph G(h*w);
  int s,g;
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      char c; cin >> c;
      if(c=='S')s = i*w+j;
      if(c=='G')g = i*w+j;
      {
        ll t = 1;
        if(c=='#')t=-1;
        if(i!=0){
          
          G[(i-1)*w+j].push_back({i*w+j,t});
        }
        if(i!=h-1){
          //G[i*h+j].push_back({(i+1)*h+j,t});
          G[(i+1)*w+j].push_back({i*w+j,t});
        }
        if(j!=0){
          //G[i*h+j].push_back({i*h+j-1,t});
          G[i*w+j-1].push_back({i*w+j,t});
        }
        if(j!=w-1){
          //G[i*h+j].push_back({i*h+j+1,t});
          G[i*w+j+1].push_back({i*w+j,t});
        }
      }
    }
  }
  ll lb = 0, ub = t*2;
  while(ub-lb>1){
    ll mb = (ub+lb)/2;
    auto d = dijkstra(s,G,mb);
    //cout << d[g] << endl;
    if(d[g]<=t){
      lb = mb;
    }
    else {
      ub = mb;
    }
  }
  cout << lb << endl;
}
