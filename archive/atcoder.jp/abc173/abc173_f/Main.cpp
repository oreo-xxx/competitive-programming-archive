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

int main() {
	ll n; cin >> n;
	ll ans = 0;

	// 頂点i個の森が,(n-i+1)個存在する
	for (int i = 1; i <= n; ++i) {
		ans += i * (n - i + 1);
	}
	// 辺(u,v)が含まれる区間は u * (n + 1 - v) 個存在する
	// 例 (2,3) は 2個 (L=1,2, R=3)存在する : 2 * (3-3+1) 
	for (int i = 0; i < n - 1; ++i) {
		ll u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		ans -= u * (n - v + 1);
	}
	cout << ans << endl;
}