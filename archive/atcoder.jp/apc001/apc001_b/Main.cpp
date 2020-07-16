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
	ll n; cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];

	ll pos = 0, neg = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		ll diff = b[i] - a[i];
		sum += diff;
		if (diff <= 0) neg -= diff;
		else pos += (diff) / 2;
	}
	string ans = "No";
	if (neg<= pos)ans = "Yes";
	cout << ans << endl;
}
