#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

Graph G;
vector<ll> A;
vector<ll> ans;

void dfs(int u, int p, vector<ll>& vec, vector<ll>& dp) {

	int idx = lower_bound(dp.begin(), dp.end(), vec.back()) - dp.begin();
	ll old = dp[idx];
	dp[idx] = vec.back();
	ans[u] = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();

	for (auto e : G[u]) {
		if (e == p) continue;
		vec.push_back(A[e]);
		dfs(e, u, vec, dp);
		vec.pop_back();
	}
	dp[idx] = old;
}

int main() {
	ll n; cin >> n;
	A.resize(n);
	for (int i = 0; i < n; ++i) cin >> A[i];

	ans.resize(n);
	G.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		ll u, v; cin >> u >> v; --u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<ll> dp(2*n, INF), buf;
	buf.push_back(A[0]);

	dfs(0, -1, buf, dp);
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}