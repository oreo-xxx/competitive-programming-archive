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

int main() {
	int n; cin >> n;
	Graph G(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<ll> c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];
	sort(c.begin(), c.end(), greater<ll>());

	queue<int> q;
	q.push(0);
	vector<ll> ans(n, -1);
	ans[0] = c[0];
	int j = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (ans[v] != -1) continue;
			ans[v] = c[j];
			++j;
			q.emplace(v);
		}
	}

	ll sum = 0;
	q.push(0);
	set<int> se;
	se.insert(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (se.count(v) != 0) continue;
			sum += min(ans[u], ans[v]);
			q.push(v);
			se.insert(v);
		}
	}

	cout << sum << endl;
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
		if (i != n - 1) cout << " ";
		else cout << endl;
	}
	return 0;
}