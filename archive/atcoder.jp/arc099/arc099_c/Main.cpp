#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<int, int>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

bool dfs(const Graph &G, int v, int vdir, pint &num, vector<int> &dir) {
    bool res = true;
    dir[v] = vdir;
    if (vdir == 1) ++num.first;
    else if (vdir == -1) ++num.second;
    for (auto nv : G[v]) {
        if (dir[nv] == 0) {
            if (!dfs(G, nv, -vdir, num, dir)) res = false;
        }
        else if (dir[nv] != -vdir) res = false;
    }
    return res;
}

bool isbipartite(const Graph &G, vector<pint> &nums) {
    bool res = true;
    int N = (int)G.size();
    vector<int> dir(N, 0);
    for (int v = 0; v < N; ++v) {
        if (dir[v] != 0) continue;
        pint num = {0, 0};
        if (!dfs(G, v, 1, num, dir)) res = false;
        nums.push_back(num);
    }
    return res;
}

int main(){
    ll n, m; cin >> n >> m;
    Graph edges(n, vector<int>(n,1));
    for(int i = 0; i < m; ++i){
	    int a, b; cin >> a >> b;
	    --a; --b;
	    edges[a][b] = 0;
	    edges[b][a] = 0;
    }

    Graph G(n);
    for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j){
			if (edges[i][j]) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}

	// 二部グラフの構成
    vector<pint> nums;
    if (!isbipartite(G, nums)) {
        cout << -1 << endl;
        return 0;
    }

	// 左右の割り振りを適切に選択することで、達成可能な個数を求める
	// 部分和問題
	int num_size = nums.size();
	vector<vector<bool>> dp(num_size + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i < num_size; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j >= nums[i].first)  dp[i + 1][j] = dp[i + 1][j] | dp[i][j - nums[i].first];
			if (j >= nums[i].second) dp[i + 1][j] = dp[i + 1][j] | dp[i][j - nums[i].second];
		}
	}
	/* 配列使いまわし
    vector<bool> dp(N+1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = N; j >= 0; --j) {
            if (dp[j] == false) continue;
            dp[j] = false;
            dp[j + nums[i].first] = true;
            dp[j + nums[i].second] = true;
        }
    }*/

	// 左右に割り振る個数を可能な限り均等にしたい(N/2に近づけたい)
    long long a = -1;
    long long dist = n;
    for (int i = 0; i <= n; ++i) {
        if (!dp[num_size][i]) continue;
        if (dist > abs(i - n/2)) dist = abs(i - n/2), a = i;
    }
    long long b = n-a;

	// クリークの辺数は N*(N-1)/2
    cout << a*(a-1)/2 + b*(b-1)/2 << endl;
}