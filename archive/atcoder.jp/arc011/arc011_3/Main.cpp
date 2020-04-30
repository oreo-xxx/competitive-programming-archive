#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

vector<int> dijkstra(int s,WeightedGraph  & G){
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
  return bs;
} 

bool check(string& a, string& b){
  int n = a.size();
  int m = b.size();
  if(n!=m) return false;
  int num = 0;
  for(int i = 0; i < n; ++i){
    if(a[i]!= b[i]){
      ++num;
    }
  }
  return num <= 1;
}

int main() {
  string s,t;cin >> s >> t;
  int n;cin >> n;
  int m = n + 2;
  vector<string> a(m);
  a[0]= s; a[m-1]= t;
  for(int i = 0; i < n; ++i){
    cin >> a[i+1];
  }
  WeightedGraph G(m);
  for(int i = 0; i < m; ++i){
    for(int j = i+1; j < m; ++j){
      if(check(a[i], a[j])){
        G[i].push_back({j,1});
        G[j].push_back({i,1});
      }
    }
  }
  
  auto bs = dijkstra(0,G);
  int cur = m-1;
  vector<int> path;
  path.push_back(cur);
  while(true){
    cur= bs[cur];
    path.push_back(cur);
    if(cur == -1){
      cout << -1 << endl;
      return 0;
    }
    if(cur == 0){
      break;
    }
  }
  int N = path.size();
  cout << N-2 << endl;
  for(int i = N-1; i >= 0; --i){
    cout << a[path[i]] << endl;
  }
}
