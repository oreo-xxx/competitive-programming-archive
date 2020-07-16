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

int dp[2100][2100];

int main() {
	int N;
	cin >> N;
	vector<int> wpos(N), bpos(N);
	for (int i = 0; i < N * 2; ++i) {
		char c; int x;
		cin >> c >> x;
		if (c == 'W') wpos[x - 1] = i;
		else          bpos[x - 1] = i;
	}

	// (B, i) の前に (B, iより大きい) + (W, j以上) が何個あるか
	vector<vector<int> > black(N, vector<int>(N + 1));
	vector<vector<int> > white(N, vector<int>(N + 1));

	for (int i = 0; i < N; ++i) {
		// (B, i) の前に (B, iより大きい) が何個あるか
		for (int j = i + 1; j < N; j++) {
			if (bpos[j] < bpos[i]) black[i][N]++;
			if (wpos[j] < wpos[i]) white[i][N]++;
		}
		// (B, i) の前に (W, j以上) が何個あるか
		for (int j = N - 1; j >= 0; j--) {
			int c1 = 0, c2 = 0;
			if (wpos[j] < bpos[i]) ++c1;
			if (bpos[j] < wpos[i]) ++c2;
			black[i][j] = black[i][j + 1] + c1;
			white[i][j] = white[i][j + 1] + c2;
		}
	}

	for (int i = 0; i < 2100; ++i) for (int j = 0; j < 2100; ++j) dp[i][j] = INF32;
	dp[0][0] = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (i < N) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + black[i][j]);
			if (j < N) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + white[j][i]);
		}
	}
	cout << dp[N][N] << endl;
}
