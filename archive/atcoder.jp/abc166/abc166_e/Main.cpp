#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
	ll n; cin >> n;
	map<ll, ll> mp, mp2;
	for (int i = 0; i < n; ++i) {
		ll a; cin >> a;
		++mp[a - (i+1)];
		++mp2[-a - (i + 1)];
	}

	ll ans = 0;
	for (auto it : mp) {
		ll k = it.first;
		ll v = it.second;
		if (mp2.count(k)) {
			ans += v * mp2[k];
		}
	}
	cout << ans << endl;

	return 0;
}