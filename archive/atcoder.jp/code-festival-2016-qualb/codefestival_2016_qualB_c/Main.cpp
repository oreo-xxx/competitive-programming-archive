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
	ll W, H; cin >> W >> H;
	priority_queue<pll, vector<pll>, greater<pll>> que;
	for (int i = 0; i < W; ++i) {
		ll val; cin >> val;
		que.push({val, 0});
	}
	for (int i = 0; i < H; ++i) {
		ll val; cin >> val;
		que.push({val, 1});
	}

	ll ans = 0, usedH = 0, usedW = 0;
	while (!que.empty()) {
		pll p = que.top(); que.pop();
		ll val = p.first;
		ll type = p.second;
		if (type == 0) {
			ans += val * (H + 1 - usedH);
			++usedW;
		}
		else {
			ans += val * (W + 1 - usedW);
			++usedH;
		}
	}
	cout << ans << endl;
	return 0;
}