#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 1;

Graph G;
vector<int> dist;

int dfs(int cur){
    int m = G[cur].size();
    if(m==0) return dist[cur] = 0;

    vector<int> vec;
    for(int i = 0; i < m; ++i){
        int e = G[cur][i];
        vec.push_back(dfs(e));
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int tmp = 0;
    for(int i = 0; i < m; ++i){
        tmp = max(tmp, i + 1 + vec[i]);
    }
    return dist[cur] = tmp;
}

void solve() {
    int n;cin >> n;
    G.resize(n);
    dist.resize(n);
    for(int i = 0; i < n-1; ++i){
        int a;cin >> a;
        --a;
        G[a].push_back(i+1);
    }
    dfs(0);
    int ans= 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, dist[i]);
    }
    cout << ans << endl;
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
