#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;


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


int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, K; cin >> N >> K;
    int maxnum = (N - 1)*(N - 2) / 2;
    if (maxnum < K){
        cout << -1 << endl;
        return 0;
    }

    // 1-indexed star-graph
    vector<P> res;
    for (int i = 1; i <= N-1; ++i) {
        res.push_back({i, N});
    }

    int rem = maxnum - K;
    int ci = 1, cj = 2;
    for (int _ = 0; _ < rem; ++_) {
        res.push_back({ci, cj});
        ++cj;
        if (cj == N) {
            ++ci;
            cj = ci + 1;
        }
    }

    cout << res.size() << endl;
    for (auto p : res){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
