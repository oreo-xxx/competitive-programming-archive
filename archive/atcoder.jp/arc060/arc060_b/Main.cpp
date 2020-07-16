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

ll calc(ll b, ll n) {
	if (n < b) 	return n;
	else return n%b + calc(b, n / b);
}

int main() {
	ll n, s; cin >> n >> s;
	if (n == s) {
		cout << n + 1 << endl;
		return 0;
	}

	// b <= √n) の場合、全探索可能
	ll root = sqrt(n);
	for (ll b = 2; b <= root; ++b) {
		ll tmp = calc(b, n);
		if (tmp == s) {
			cout << b << endl;
			return 0;
		}
	}

	// b >= √n の場合
	//   n = p*b + q (q < b)
	//   s = p + q
	// b >= √nなので、
	// n >= p * √n + q -> p <= √n
	// p == 0の場合 -> n==sなので検査済み
	ll ans = -1;
	for (ll p = 1; p <= root; ++p) {
		ll q = s - p;
		ll b = (n-s)/p + 1;
		if (b <= root || q > b) continue;
		ll tmp = calc(b, n);
		if (tmp == s) {
			ans = b;
		}
	}

	cout << ans << endl;
	return 0;
}