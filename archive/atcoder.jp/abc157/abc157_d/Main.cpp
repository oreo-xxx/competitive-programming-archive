#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;


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


void solve() {
    ll N, M, K; cin >> N >> M >> K;
    UnionFind uf(N);
    vector<ll> vec(N);
    for(int i = 0; i < M; ++i){
        ll a, b; cin >> a >> b;
        --a;--b;
        uf.merge(a,b);
        --vec[a];
        --vec[b];
    }
    for(int i = 0; i < K; ++i){
        ll a, b; cin >> a >> b;
        --a;--b;
        if(uf.issame(a,b)){
            --vec[a];
            --vec[b];
        }
    }
    for (int i = 0; i < N; ++i) {
        vec[i] += uf.size(i)-1;
    }
    for (int i = 0; i < N; ++i) {
        cout << vec[i];
        if(i == N-1) cout << endl;
        else cout << ' ';
    }
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
