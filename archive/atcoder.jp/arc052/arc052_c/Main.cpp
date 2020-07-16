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

// Bを通る本数が少ないようにダイクストラ
// 値の更新をキュー追加後とすることで、
// Bを経由してでも距離最小化するパターンが成立
//  (可能な限りBは少ない数で進みたい
//    + 局所的にはB通ってでも進むべき時がある)

vector<ll> dijkstra(int s, WeightedGraph& G) {
	using P = pair<pll, ll>;
	int n = G.size();
	vector<ll> ds(n, INF);
	priority_queue<P, vector<P>, greater<P>> pq;
	ds[s] = { 0 };
	pq.push({ {ds[s], 0}, s });
	while (!pq.empty()) {
		P p = pq.top(); pq.pop();
		ll u = p.second;
		if (ds[u] < p.first.second) continue;

		ds[u] = p.first.second; // 値の更新はキュー追加後

		for (auto& e : G[u]) {
			ll u = e.first;
			ll type = e.second;

			ll bnum = p.first.first;
			ll cost = p.first.second + 1;
			if (type == 1) {
				cost += bnum;
				++bnum;
			}

			if (ds[u] > cost) {
				pq.push({ {bnum, cost}, u});
			}
		}
	}
	return ds;
}


int main() {
	ll n, m; cin >> n >> m;
	WeightedGraph G(n);
	for (int i = 0; i < m; ++i) {
		ll a, b, c; cin >> c >> a >> b;
		G[a].push_back({ b, c });
		G[b].push_back({ a, c });
	}

	auto d = dijkstra(0, G);
	for (int i = 0; i < n; ++i) {
		cout << d[i] << endl;
	}
}
