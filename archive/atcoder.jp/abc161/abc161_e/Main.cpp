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

int n, k, c;

vector<ll> count(const string& s) {
	int cur = 0, last = -c-1;
	vector<ll> res(n + 1);
	for (int i = 0; i < n; ++i) {
		if (i - last > c && s[i] == 'o') {
			++cur;
			last = i;
		}
		res[i+1] = cur;
	}
	return res;
}

int main() {
	string s;
	cin >> n >> k >> c >> s;
	string t = s;
	reverse(t.begin(), t.end());

	auto v1 = count(s);
	auto v2 = count(t);

	// iを使わない場合の最大値を合計する
	for (int i = 0; i < n; ++i) {
		if (s[i] != 'o') continue;
		if (v1[i] + v2[n-1-i] < k) {
			cout << i + 1 << endl;
		}
	}

	return 0;
}