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

int main(){
	ll n; cin >> n;
	vector<ll> pos(n+1);
	for(int i = 0; i < n; ++i){
		ll a; cin >> a;
		pos[a] = i+1;
	}

	ll ans = 0;
	set<ll> se{0, n+1};
	for(ll i = n; i > 0; --i){
		auto r1 = se.lower_bound(pos[i]);
		auto l1 = r1;
		--l1;

		ll num = 0;

		if (*l1 != 0) {
			auto l2 = l1;
			--l2;
			num += (*l1 - *l2) * (*r1 - pos[i]);
		}

		if (*r1 != n+1) {
			auto r2 = r1;
			++r2;
			num += (pos[i] - *l1) * (*r2 - *r1);
		}

		ans += num * i;
		se.insert(pos[i]);
	}
	cout << ans << endl;
	return 0;
}