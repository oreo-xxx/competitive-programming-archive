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

struct UnionFind {
	vector<int> par, rank;

	UnionFind(int n) : par(n, -1), rank(n, 0) { }
	void init(int n) { par.assign(n, -1), rank.assign(n, 0); }

	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		return true;
	}
};


int main() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	UnionFind uf(n - k + 1);
	
	// もともと昇順な範囲を尺取りで連結
	int r = 1, sorted = -1;
	for (int l = 0; l + k-1 < n;) {
		while (r < n && a[r] > a[r - 1]) {
			++r;
			if (r - l >= k) {
				if(sorted!=-1) uf.merge(sorted, r - k);
				else sorted = l;
			}
		}
		l = r;
		++r;
	}

	// Setでi, i+1がequivalentか判定
	set<ll> se;
	for (int i = 0; i < k; ++i)	se.insert(a[i]);

	for (int l = 0; l + k < n; ++l) {
		ll kl = a[l]; // iの範囲の左端
		ll kr = a[l + k]; // i+1の範囲の右端
		se.erase(kl);
		ll m = *se.begin(); // 共通部分の最小値
		ll M = *se.rbegin(); // 共通部分の最大値
		if (kl < m && M < kr) uf.merge(l, l + 1);
		se.insert(kr);
	}

	// 連結成分を数える
	ll ans = 0;
	for (int i = 0; i < n - k + 1; ++i) {
		if (uf.par[i] == -1) ++ans;
	}
	cout << ans << endl;
	return 0;
}