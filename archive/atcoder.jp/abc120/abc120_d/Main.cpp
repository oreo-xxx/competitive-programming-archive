#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i], --A[i], --B[i];
    }

    UnionFind uf(N);

    // 操作を逆順
    ll cur = N * (N-1) / 2;
    vector<ll> res;
    for (int i = 0; i < M; ++i) {
        res.push_back(cur);

        int a = A[M-1-i], b = B[M-1-i];
        if (uf.issame(a, b)) continue;

        ll sa = uf.size(a), sb = uf.size(b);
        cur -= sa * sb;
        uf.merge(a, b);
    }

    // 出力のため反転
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i){
        cout << res[i] <<endl;
    }

    return 0;
}

