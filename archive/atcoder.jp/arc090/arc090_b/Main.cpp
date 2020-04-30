#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
template<class Abel> struct UnionFind {
    const Abel UNITY_SUM = 0;      // to be set
    vector<int> par;
    vector<Abel> diff_weight;

    UnionFind(int n) : par(n, -1), diff_weight(n, UNITY_SUM) {}
    void init(int n) { par.assign(n, -1), diff_weight.assign(n, UNITY_SUM); }

    int root(int x) {
        if (par[x] < 0) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel calc_weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w = 0) {
        w += calc_weight(x); w -= calc_weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y), w = -w; // merge technique
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return calc_weight(y) - calc_weight(x);
    }

    int size(int x) {
        return -par[root(x)];
    }
};
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N, M; cin >> N >> M;
    UnionFind<int> uf(N);
    for (int i = 0; i < M; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (uf.issame(l, r)) {
            int diff = uf.diff(l, r);
            if (diff != d) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            uf.merge(l, r, d);
        }
    }
    cout << "Yes" << endl;
    return 0;
}

