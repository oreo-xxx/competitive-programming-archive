#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

using Graph = vector<vector<int> >;
struct LowLink {
    // main results
    vector<int> aps; // articulation points
    vector<pair<int,int> > brs; // brideges

    // intermediate results
    vector<int> seen, ord, low;
    void dfs_lowlink(const Graph &G, int v, int p = -1) {
        static int time = 0;
        seen[v] = true;
        ord[v] = low[v] = time++;
        int num_of_child = 0;
        bool exist = false; // for articulation point
        for (auto ch : G[v]) {
            if (seen[ch]) {
                if (ch != p) low[v] = min(low[v], ord[ch]); // back edge
                continue;
            }
            dfs_lowlink(G, ch, v);
            low[v] = min(low[v], low[ch]); // forward edge of DFS-tree
            if (ord[v] < low[ch]) brs.emplace_back(v, ch);
            if (ord[v] <= low[ch]) exist = true;
            ++num_of_child;
        }
        if ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);
    }
    void solve(const Graph &G) {
        int N = (int)G.size();
        seen.assign(N, 0); ord.resize(N); low.resize(N);
        aps.clear(); brs.clear();
        for (int v = 0; v < N; ++v) if (!seen[v]) dfs_lowlink(G, v);
    }
};

void solve(){
    int N, M; cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; ++i){
        int s, t; cin >> s >> t; --s; --t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    LowLink ll;
    ll.solve(G);
    cout << ll.brs.size() << '\n';
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt"};
    cout << "------------\n";
    for(auto filename : filenames){
        ifstream in(filename);
        cin.rdbuf(in.rdbuf());
#endif
        solve();

#ifdef MYLOCAL
        cout << "------------\n";
    }
#endif
  return 0;
}

