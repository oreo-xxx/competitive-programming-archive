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
	string s; cin >> s;
	int n = s.size();
	bool f = true;
	if (s[0] == '0') f = false;
	if (s[n-1] == '1') f = false;
	for (int i = 0; i < n-1; ++i) {
		if (s[i] != s[n - 2 - i]) f = false;
	}

	if (!f) {
		cout << -1 << endl;
		return 0;
	}

	int now = 1;
	for (int i = 1; i < n; ++i) {
		cout << now << " " << i+1 << endl;
		if (s[i-1] == '1')now = i+1;
	}

	return 0;
}