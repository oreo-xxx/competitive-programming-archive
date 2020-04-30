#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

struct UnionFind {
    vector<int> par, rank;

    UnionFind(int n) : par(n , -1), rank(n, 0) { }
    void init(int n) { par.assign(n, -1), rank.assign(n, 0); }

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N, M; cin >> N >> M;
    vector<int> p(N);
    map<int, int> mp;
    for(int i = 0; i < N; ++i){
        cin >> p[i];
        --p[i];
        mp[p[i]] = i;
    }

    UnionFind uf(N);
    for(int i = 0; i < M; ++i){
        int x, y; cin >> x >> y;
        --x; --y;
        uf.merge(mp[x], mp[y]);
    }

    int ans = 0;
    for(int i = 0; i < N; ++i){
        if( uf.root(p[i]) == uf.root(i)){
            ++ans;
        }
        else if(p[i] == i){
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}

