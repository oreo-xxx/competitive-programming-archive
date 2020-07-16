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
	ll n, k; cin >> n >> k;
	string s; cin >> s;

	map<vector<int>, int> mp;
	vector<int> vec(26);
	for (int i = 0; i < k; ++i) {
		++vec[s[i] - 'a'];
	}
	mp[vec] = 0;

	string ans = "NO";
	for (int i = 0; i + k < n; ++i) {
		--vec[s[i] - 'a'];
		++vec[s[i + k] - 'a'];
		if (mp.count(vec)) {
			if (i+1 - mp[vec] >= k) {
				ans = "YES";
				break;
			}
		}
		else {
			mp[vec] = i;
		}
	}
	cout << ans << endl;
	return 0;
}