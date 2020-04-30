#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

// 入力
int N;
Graph G;
vector<int> ans;

// v を c に塗る。p は v の親
void dfs(int v, int p, int c) {
    ans[v] = c;
    for (auto e : G[v]) {
        if (e.first == p){
            continue;
        }
        
        if (e.second & 1){
            dfs(e.first, v, 1-c);
        }
        else{
            dfs(e.first, v, c);
        }
    }
}

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    ans.resize(N);
    G.assign(N, vector<Edge>());
    for (int i = 0; i < N-1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }

    dfs(0, -1, 1);
    for (auto v : ans){
        cout << v << endl;
    }
    return 0;
}
