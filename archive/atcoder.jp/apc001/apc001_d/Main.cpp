#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ld>;
using Graph = vector<vector<int> >;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 30;
const int MOD = 1e9+7;

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

void pq_merge(priority_queue<ll>& dst, priority_queue<ll>& src) {
	if (src.size() > dst.size()) swap(src, dst);
	while (!src.empty()) {
		dst.push(src.top()); src.pop();
	}
}


int main() {
	ll N, M; cin >> N >> M;

	vector<ll> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	if (M == N - 1) {
		cout << 0 << endl;
		return 0;
	}


	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		uf.merge(a, b);
	}

	vector<priority_queue<ll>> p_que(N);
	for (int i = 0; i < N; ++i) {
		int p = uf.root(i);
		p_que[p].push(-1 * a[i]);
	}

	ll cnt = 2 * (N - 1 - M);

	ll ans = 0;
	priority_queue<ll> que;
	for (int i = 0; i < N; ++i) {
		if (!p_que[i].empty()) {
			ans -= p_que[i].top(); p_que[i].pop();
			pq_merge(que, p_que[i]);
			--cnt;
		}
	}

	for (; cnt > 0; --cnt) {
		if (que.empty()) {
			ans = -1; break;
		}
		ans -= que.top(); que.pop();
	}
	if(ans == -1) cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}