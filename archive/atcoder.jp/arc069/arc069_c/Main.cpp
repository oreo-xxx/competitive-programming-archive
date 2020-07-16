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
	ll n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	// 現時点での最大値を、その次の値に追いつくまで連続して減らす
	// 辞書順にするため、右のインデックスから減らしていく
	// そのため、左端のインデックスと、同一値の数が必要になる
	map<ll, ll> midx, count;
	for (ll i = 0; i < n; ++i) {
		++count[a[i]];
		if (midx.count(a[i]) == 0) midx[a[i]] = i;
		// midx.try_emplace(a[i] , i);
	}


	map<ll, ll> ans;
	ll sum = 0;
	for (auto it = count.rbegin(); it != count.rend(); ++it) {
		ll val = it->first;
		ll num = it->second;

		auto ne = it; ++ne;
		ll nval = 0;
		if (ne != count.rend()) nval = ne->first;

		ans[midx[val]] += (val - nval)*(sum + num);

		// 追いつくたびに、同一値の数は累積する
		sum += num;

		// 追いつくたびに、左端インデックスの更新を確認
		midx[nval] = min(midx[nval], midx[val]);
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}