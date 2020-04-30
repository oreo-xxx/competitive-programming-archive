#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
struct edge{
  int u; int v; ll c;
};
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<edge>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
int n,m;

ll Bellman(int s, int t, WeightedGraph& G){
  vector<ll> d(n);
  for(int i = 0; i < n; ++i)d[i]=INF;
  d[0]=0;
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < m; ++j){
      int u = G[j].u;
      int v = G[j].v;
      ll c = G[j].c;
      if(d[v]>d[u]+c){
        d[v]=d[u]+c;
      }
    }
  }
  vector<bool> pos(n, false);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      int u = G[j].u;
      int v = G[j].v;
      ll c = G[j].c;
      if(d[u]>INF32)continue;
      if(d[v]>d[u]+c){
        pos[v] = true;
      }
      if(pos[u]) pos[v] = true; 
    }
  }
  //for(int i = 0; i < n; ++i)cout << pos[i] << endl;
  if(pos[n-1])return 1;
  return min(d[n-1],0LL);
}

int main(){
  ll p;cin >> n >> m >> p;
  WeightedGraph G(m);
  for(int i = 0; i < m; ++i){
    int a, b; ll c; cin >> a >> b >> c;
    --a;--b;
    G[i]={a, b,-1*c+p};
  }
  ll ans = Bellman(0, n-1, G);
  cout << -1*ans << endl;
}
