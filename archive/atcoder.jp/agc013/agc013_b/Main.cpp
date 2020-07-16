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
const ll MOD = 998244353;

int main() {
	ll n, m; cin >> n >> m;
	Graph G(n);
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// 適当なパスを構築
	deque<int> ans;
	ans.emplace_front(0);
	ans.emplace_back(G[0][0]);

	// 探索済み頂点を管理
	unordered_set<int> se;
	se.insert(0);
	se.insert(G[0][0]);

	// 始点を条件満たすまで更新
	while (true) {
		int now = ans.front();
		bool f = true;
		for (auto e : G[now]) {
			if (se.count(e)) continue;
			se.insert(e);
			ans.emplace_front(e);
			f = false;
			break;
		}
		if (f) break;
	}

	// 終点を条件満たすまで更新
	while (true) {
		int now = ans.back();
		bool f = true;
		for (auto e : G[now]) {
			if (se.count(e)) continue;
			se.insert(e);
			ans.emplace_back(e);
			f = false;
			break;
		}
		if (f) break;
	}

	int N = ans.size();
	cout << N << endl;
	for (int i = 0; i < N; ++i) {
		cout << ans[i]+1;
		if (i != N - 1) cout << " ";
		else cout << endl;
	}

	return 0;
}