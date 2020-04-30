#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
bool chmin(long long &a, long long b) { if (a > b) {a = b; return true;} return false;}
using Edge = pair<int, long long>;
int N, M;
vector<vector<Edge> > G;
int main(){
    cin >> N >> M;
    G.clear(); G.resize(N);
    for (int i = 0; i < M; ++i) {
        int a, b; long long w;
        cin >> a >> b >> w; --a, --b;
        G[a].push_back(Edge(b, -w));
    }

    vector<long long> dist(N, INF);
    bool negative = false;
    dist[0] = 0;
    for (int iter = 0; iter <= N*2; ++iter) {
        for (int v = 0; v < N; ++v) {
            if (dist[v] >= INF/2) continue;
            for (auto e : G[v]) {
                if (chmin(dist[e.first], dist[v] + e.second)) {
                    if (e.first == N-1 && iter == N*2) negative = true;
                }
            }
        }
    }
    if (!negative) cout << -dist[N-1] << endl;
    else cout << "inf" << endl;

}