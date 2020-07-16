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

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int h, w;
int sx, sy;
vector<string> s;
vector<vector<int>> steps;

void bfs() {
	queue<pint> q;
	steps[sy][sx] = 0;
	q.push({ sx,sy });
	while (!q.empty()) {
		pint it = q.front(); q.pop();
		int x = it.first;
		int y = it.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
			if (s[ny][nx] == '#') continue;
			if (steps[ny][nx] != INF32) continue;
			steps[ny][nx] = steps[y][x] + 1;
			q.emplace(nx, ny);
		}
	}
	return;
}

int main() {
	int K;
	cin >> h >> w >> K;
	s.resize(h);
	steps.resize(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
		steps[i].resize(w, INF32);
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == 'S') sy = i, sx = j;
		}
	}

	bfs();
	set<pint> se;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (steps[i][j] <= K) se.insert({j, i});
		}
	}

	int ans = INF32;
	for (auto it : se) {
		int x = it.first;
		int y = it.second;
		int M = min(x, min(y, min(h-1 - y, w-1 - x)));
		ans = min(ans, (M + K - 1) / (K));
	}
	cout << ans+1 << endl;
	return 0;
}