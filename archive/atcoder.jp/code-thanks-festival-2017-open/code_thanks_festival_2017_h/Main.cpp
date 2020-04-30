#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
struct PartiallyPersistentUnionFind {
    vector<int> par, last;
    vector<vector<P> > history;

    PartiallyPersistentUnionFind(int n) : par(n, -1), last(n, -1), history(n) {
        for (auto &vec : history) vec.emplace_back(-1, -1);
    }
    void init(int n) {
        par.assign(n, -1); last.assign(n, -1); history.assign(n, vector<P>());
        for (auto &vec : history) vec.emplace_back(-1, -1);
    }

    int root(int t, int x) {
        if (last[x] == -1 || t < last[x]) return x;
        return root(t, par[x]);
    }

    bool issame(int t, int x, int y) {
        return root(t, x) == root(t, y);
    }

    bool merge(int t, int x, int y) {
        x = root(t, x); y = root(t, y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        last[y] = t;
        history[x].emplace_back(t, par[x]);
        return true;
    }

    int size(int t, int x) {
        x = root(t, x);
        return -prev(lower_bound(history[x].begin(), history[x].end(), make_pair(t, 0)))->second;
    }
};
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, M; cin >> N >> M;;
    PartiallyPersistentUnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        uf.merge(i + 1, a, b);
    }

    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x, y;  cin >> x >> y;
        --x, --y;
        if (!uf.issame(M + 10, x, y)){
            cout << -1 << endl;
        }
        else {
            int low = 0, high = M + 10;
            while (high - low > 1) {
                int mid = (low + high) / 2;
                if (uf.issame(mid, x, y)) high = mid;
                else low = mid;
            }
            cout << high << endl;
        }
    }
    return 0;
}

