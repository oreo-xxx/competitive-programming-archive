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
	map<int, vector<int>> mp;

	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		mp[a].push_back(i);
	}

	int ans = 1, now = -1;
	for (auto it : mp) {
		int idx = lower_bound(it.second.begin(), it.second.end(), now) - it.second.begin();
		//cout << idx << endl;
		if (idx == 0) {
			now = it.second.back();
		}
		else {
			++ans;
			now = it.second[idx - 1];
		}
	}
	if (now == 0) --ans;
	cout << ans << endl;
	return 0;
}