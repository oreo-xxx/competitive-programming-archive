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

int main() {
	int N, M; cin >> N >> M;
	vector<string> a(N), b(M);
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < M; ++i) cin >> b[i];

	string ans = "No";
	for (int i = 0; i + (M - 1) < N; ++i) {
		for (int j = 0; j + (M - 1) < N; ++j) {
			bool f = true;
			for (int k = 0; k < M; ++k) {
				for (int l = 0; l < M; ++l) {
					if (a[i + k][j + l] != b[k][l]) f = false;
				}
			}
			if (f) {
				ans = "Yes";
				break;
			}
		}
	}
	cout << ans << endl;
}