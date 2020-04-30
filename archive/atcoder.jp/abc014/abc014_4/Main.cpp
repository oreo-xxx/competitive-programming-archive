#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

using Graph = vector<vector<int> >;
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
    int dist(int u, int v){
        return depth[u]+depth[v]-depth[get(u,v)]*2;
    }
};

int main() {
	int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a>> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    LCA lca(G);
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int u, v; cin >> u >> v;
        --u;--v;
        cout << lca.dist(u, v) + 1<< endl;
    }
}
