#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

using Graph = vector<vector<int>>;

int N, M;
Graph G;
int s, t;

ll bfs() {
    vector<vector<ll>> dist(N, vector<ll>(3, -1));
    dist[s][0] = 0;
    queue<P> que;
    que.push({s, 0});
    while (!que.empty()) {
        P cur = que.front(); que.pop();
        int v = cur.first;
        int parity = cur.second;
        for (auto nv : G[v]) {
            int np = (parity + 1) % 3;
            if (dist[nv][np] == -1) {
                dist[nv][np] = dist[v][parity] + 1;
                que.push({nv, np});
            }
        }
    }
    if (dist[t][0] == -1){
        return -1;
    }
    else{
        return dist[t][0] / 3;
    }
}

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> M;

    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }

    cin >> s >> t;
    --s, --t;
    cout << bfs() << endl;
    return 0;
}
