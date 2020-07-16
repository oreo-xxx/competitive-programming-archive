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
	bool f = false;
	for(int i = 0; i < n; ++i){
		ll a; cin >> a;
		if (a % 2 != 0) f = true;
	}
	string ans = "second";
	if (f) ans = "first";
	cout << ans << endl;
	return 0;
}