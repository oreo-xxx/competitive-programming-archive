#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//
int N, M;
vector<vector<int> > G;


vector<bool> seen;
bool rec(int v, int p, int s, int t) {
    if (v == s && p != -1) return true; // 一周回ってきて s に戻って来たら OK
    if (v != s) seen[v] = true;
    for (auto nv :  G[v]) {
        if (nv == p || nv == t || seen[nv]) continue;
        if (rec(nv, v, s, t)) return true;
    }
    return false;
}

bool solve() {
    map<int,int> degs;
    for (int v = 0; v < N; ++v) degs[G[v].size()]++;
    // 次数チェック
    for (auto it : degs) if (it.first % 2 != 0) return false;
    if (degs[6] > 0) return true;
    if (degs[4] > 2) return true;
    if (degs[4] <= 1) return false;

    // 次数4 == 2 の場合
    vector<int> four;
    for (int v = 0; v < N; ++v) if (G[v].size() == 4) four.push_back(v);
    int s = four[0], t = four[1];
    seen.assign(N, 0);
    return rec(s, -1, s, t);
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
