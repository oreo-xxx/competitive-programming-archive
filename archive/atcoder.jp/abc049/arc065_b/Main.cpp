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
    int N, K, L; cin >> N >> K >> L;
    UnionFind ufk(N);
    for(int i = 0; i < K; ++i){
        int x, y; cin >> x >> y;
        --x; --y;
        ufk.merge(x, y);
    }

    UnionFind ufl(N);
    for(int i = 0; i < L; ++i){
        int x, y; cin >> x >> y;
        --x; --y;
        ufl.merge(x, y);
    }
    map<P, int> mp;
    for(int i = 0; i < N; i++){
        int a = ufk.root(i);
        int b = ufl.root(i);
        mp[make_pair(a, b)]++;
    }

    for (int i = 0; i < N; ++i) {
        int a = ufk.root(i);
        int b = ufl.root(i);
        cout << mp[{a,b}];
        if(i == N - 1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
    return 0;
}

