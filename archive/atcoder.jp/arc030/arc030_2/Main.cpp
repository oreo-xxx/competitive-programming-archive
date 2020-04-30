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

Graph tree;

struct LCA {
    vector<vector<int> > parent; // parent[d][v] := 2^d-th parent of v
    vector<int> depth;
    LCA() { }
    LCA(const Graph &G, int r = 0) { init(G, r); }
    void init(const Graph &G, int r = 0) {
        int V = (int)G.size();
        int h = 1;
        while ((1<<h) < V) ++h;
        parent.assign(h, vector<int>(V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for (int i = 0; i+1 < (int)parent.size(); ++i)
            for (int v = 0; v < V; ++v)
                if (parent[i][v] != -1)
                    parent[i+1][v] = parent[i][parent[i][v]];
    }
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto e : G[v]) if (e != p) dfs(G, e, v, d+1);
    }
    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = 0; i < (int)parent.size(); ++i)
            if ( (depth[v] - depth[u]) & (1<<i) )
                v = parent[i][v];
        if (u == v) return u;
        for (int i = (int)parent.size()-1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
};


int main() {
  int n,x;cin >> n >> x;
  --x;
  vector<int> h(n);
  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }
  tree.resize(n);
  for(int i = 0; i < n-1; ++i){
    int a,b;cin >> a >> b;
    --a;--b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  LCA lca(tree, x);
  
  int ans = 0;
  set<pint> se;
  for(int i = 0; i < n; ++i){
    if(h[i]==0) continue;
    int cur=i;
    while(cur!=x){
      int next = lca.parent[0][cur];
      se.insert({min(cur, next), max(cur, next)});
      cur = next;
    }
  }
  
  for(auto p : se){
    int i = p.first;
    int j= p.second;
    ans += 2 * abs(lca.depth[i]-lca.depth[j]);
  }
  cout << ans << endl;
}
