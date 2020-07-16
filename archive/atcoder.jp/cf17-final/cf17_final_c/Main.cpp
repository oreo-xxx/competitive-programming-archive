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
	map<int, int> mp;
	for(int i = 0; i < 13; ++i) mp[i] = 0;
	++mp[0];
	for(int i = 0; i < n; ++i){
		int a; cin >> a;
		++mp[a];
	}

	bool f = false;
	for(int i = 0; i < 13; ++i) if(mp[i] >= 3) f = true;
	if(mp[0] >= 2 || mp[12] >= 2) f = true;
	if(f){
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	for(int s = 0; s < (1 << 13); ++s){
		bitset<12> bs(s);
		vector<int> times{ 0, 24 };
		for (int i = 1; i < 13; ++i) {
			if (mp[i] == 1) {
				if (bs[i-1]) times.push_back(i);
				else times.push_back(24 - i);
			}
			else if (mp[i] == 2) {
				times.push_back(i);
				times.push_back(24 - i);
			}
		}
		sort(times.begin(), times.end());
		int tmp = INF32;
		for (int i = 1; i < times.size(); ++i) {
			tmp = min(tmp, times[i] - times[i-1]);
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}