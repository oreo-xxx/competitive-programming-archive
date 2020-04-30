#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

ll dp[1000001] = {};

int n, m;
vector<vector<int> > G;

int rec(int v) {
    if (dp[v] != -1) {
        return dp[v];
    }

    int res = 0;
    for (auto next_v : G[v]) {
        res = max(res, rec(next_v) + 1);
    }

    return dp[v] = res;
}

int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    cin >> n >> m;
    G.resize(n);
    for(int i = 0; i < m; ++i){
        int from, to; cin >> from >> to;
        --from;
        --to;
        G[from].push_back(to);
    }

    for(int i = 0; i <= n; ++i){
        dp[i] = -1;
    }

    int res = 0;
    for (int v = 0; v < n; ++v) {
        res = max(res, rec(v));
    }

    cout << res << endl;

    return 0;
}