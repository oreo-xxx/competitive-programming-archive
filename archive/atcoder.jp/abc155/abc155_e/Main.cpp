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

ll dp[1001000][2]{};

int main() {
	string s; cin >> s;
	s = "0" + s;
	int n = s.size();

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = INF;

	dp[0][0] = 0;

	for (int i = 0; i < n; ++i) {
		int c = s[i] - '0'; 
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + c);          // 繰り下がりなし + 繰り下がりなし
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c + 1);      // 繰り下がりなし + 繰り下がり発生
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 10 - c);     // 繰り下がりあり + 繰り下がりさせない
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 10 - c - 1); // 繰り下がりあり + 繰り下がり発生
	}
	cout << dp[n][0] << endl;

	return 0;
}