#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//
int N, K;
vector<vector<int> > tree;

// 頂点 v を根として、p のある側は切り落としてできる部分木について
// v から各頂点への距離を depth に格納する
// (特に p = -1 のときは、ツリー全体について v を根とすることを表す)
void rec(int v, int p, int curdepth, vector<int> &depth) {
    depth[v] = curdepth;
    for (auto nv : tree[v]) {
        if (nv == p) continue;
        rec(nv, v, curdepth + 1, depth);
    }
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> K;
    tree.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b); tree[b].push_back(a);
    }
    int res = N; // INF の気持ち
    vector<int> depth(N);
    if (K % 2 == 0) {
        for (int v = 0; v < N; ++v) {
            rec(v, -1, 0, depth);
            int num = 0;
            for (int i = 0; i < N; ++i) if (depth[i] > K/2) ++num;
            res = min(res, num);
        }
    }
    else {
        for (int u = 0; u < N; ++u) {
            for (auto v : tree[u]) {
                depth[v] = depth[v] = 0;
                rec(u, v, 0, depth); rec(v, u, 0, depth);
                int num = 0;
                for (int i = 0; i < N; ++i) if (depth[i] > K/2) ++num;
                res = min(res, num);
            }
        }
    }
    cout << res << endl;
}
