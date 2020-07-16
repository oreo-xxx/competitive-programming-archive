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
	const ll M = 1000100;
	vector<ll> a(M), sum(M+1);
	for(int i = 0; i < n; ++i){
		ll s; cin >> s; --a[s];
	}
	a[0] = 0;
	for(int i = M-1; i >=0; --i) sum[i] = a[i] + sum[i+1];
	
	ll Q; cin >> Q;
	vector<ll> ans(Q);
	for(int i = 0; i < Q; ++i){
		ll k; cin >> k;	k *= -1;
		int idx = lower_bound(sum.begin(), sum.end(), k) - sum.begin();
		ans[i] = idx;
	}

	for (int i = 0; i < Q; ++i) cout << ans[i] << endl;

	return 0;
}