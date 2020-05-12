#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int main() {
	int H, W; cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) cin >> s[i];

	vector<pint> blacks;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (s[i][j] == '#')blacks.push_back({i, j});
		}
	}

	vector<vector<int>> used(H, vector<int>(W));
    ll ans = 0;
	for (auto start : blacks) {
		if (used[start.first][start.second] != 0) continue;

		map<char, ll> mp;
		queue<pint> que;

		used[start.first][start.second] = 1;
		++mp[s[start.first][start.second]];
		que.push(start);
		while (!que.empty()) {
			pint p = que.front(); que.pop();
			int y = p.first;
			int x = p.second;
			for (int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;
				if (s[ny][nx] == s[y][x]) continue;
				if (used[ny][nx] != 0) continue;
				used[ny][nx] = 1;
				++mp[s[ny][nx]];
				que.push({ ny,nx });
			}
		}
		ans += mp['#'] * mp['.'];
	}
	cout << ans << endl;
}
