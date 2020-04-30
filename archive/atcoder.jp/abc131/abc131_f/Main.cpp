#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
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
//

const ll MAX = 110000;

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll N; cin >> N;

    UnionFind uf(MAX * 2);
    for (int i = 0; i < N; ++i){
        ll x, y;
        cin >> x >> y;
        uf.merge(x, y + MAX);
    }

    // 連結成分ごとに、左ノードと右ノードの個数を数える
    map<int, ll> mx, my;
    for (int i = 0; i < MAX; ++i){
        mx[uf.root(i)]++;
    }
    for (int i = MAX; i < MAX*2; ++i){
        my[uf.root(i)]++;
    }

    ll res = 0;
    for (int r = 0; r < MAX*2; ++r){
        res += mx[r] * my[r];
    }

    cout << res- N << endl;
    return 0;
}
