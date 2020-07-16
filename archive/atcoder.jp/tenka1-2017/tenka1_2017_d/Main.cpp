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
	ll n, k; cin >> n >> k;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if ((k | a[i]) == k) ans += b[i];
	}

	for (int bit = 0; bit < 32; ++bit) {
		bitset<32> bk = k;
		if (!bk[bit]) continue;

		bk[bit] = 0;
		for (int i = 0; i < bit; ++i) bk[i] = 1;

		ll x = bk.to_ullong(), tmp = 0;
		for (int i = 0; i < n; ++i) {
			if ((x | a[i]) == x) tmp += b[i];
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}