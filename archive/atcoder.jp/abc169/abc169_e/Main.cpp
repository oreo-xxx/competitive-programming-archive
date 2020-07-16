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
	vector<pll> ab(n), ba(n);
	vector<ll> comp;
	for(int i = 0; i < n; ++i){
		cin >> ab[i].first >> ab[i].second;
		ba[i] = ab[i];
		swap(ba[i].first, ba[i].second);
	}
	sort(ab.begin(), ab.end());
	sort(ba.begin(), ba.end(), greater<pll>());
	ll s = 0, e = 0;
	if(n % 2 == 0){
		s = ab[n / 2 - 1].first + ab[n / 2].first;
		e = ba[n / 2 - 1].first + ba[n / 2].first;
	}
	else{
		s = ab[n / 2].first;
		e = ba[n / 2].first;
	}
	ll ans = e - s + 1;
	cout << ans << endl;
}