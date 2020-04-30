#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

using Edge = pair<int, int>;
using Graph = vector<vector<Edge> >;

// 入力
int N;
Graph G;
map<P, int> mp;
set<int> se;

// v を c に塗る。p は v の親
void dfs(int v, int p, int c) {
    int count = 1;
    if(count == c) ++count;
    for (auto& e : G[v]) {
        if (e.first == p){
            continue;
        }

        e.second = count;
        mp[{v, e.first}] = e.second;
        se.insert(count);
        dfs(e.first, v, count);

        ++count;
        if(count == c) ++count;
    }
}

void solve() {
    cin >> N;
    G.assign(N, vector<Edge>());
    vector<P> ans;
    ans.resize(N-1);

    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        ans[i] = {u,v};
        G[u].push_back(Edge(v, 0));
        G[v].push_back(Edge(u, 0));
    }

    dfs(0, -1, -1);

    cout << se.size() << endl;
    for(int i = 0; i < N-1; ++i){
        cout << mp[ {ans[i].first, ans[i].second} ] << endl;
    }
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
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

