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
const ll MOD = 998244353;

int main() {
	ll N; cin >> N;
	vector<pll> vec(N);
	// Rを半開区間 + L昇順・R降順にソート
	for (int i = 0; i < N; ++i) {
		cin >> vec[i].first >> vec[i].second;
		++vec[i].second;
		vec[i].second *= -1;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; ++i) {
		vec[i].second *= -1;
	}

	// L最大はソートしたため右端の要素
	ll L = vec[N - 1].first;
	ll LR = vec[N - 1].second;
	// R最小を探す
	ll R = INF, tmp = -1, RL = 0;
	for (int i = 0; i < N; ++i) {
		if (R > vec[i].second) {
			tmp = i;
			R = vec[i].second;
			RL = vec[i].first;
		}
	}

    //TODO: ここ修正。
    // L最小とR最大が一致していなくとも、
    // 同一グループとしてシュミレーションするのが抜けてる？
	if (tmp == N - 1) {
		// 最大区間と最小区間の和
		ll LONGEST = 0;
		for (int i = 0; i < N; ++i) LONGEST = max(LONGEST, vec[i].second - vec[i].first);
		ll SHORTEST = LR - L;
		cout << LONGEST + SHORTEST << endl;
	}
	else {
		vec.erase(tmp + vec.begin());
		vec.pop_back();
		N = N - 2;
        // 同一グループにした場合
		ll LONGEST = 0;
		for (int i = 0; i < N; ++i) LONGEST = max(LONGEST, vec[i].second - vec[i].first);
		ll ans = max(R-L, 0LL) + LONGEST;

        // 別グループにした場合
		vector<ll> tR(N + 1, LR);
		for (int i = N - 1; i >= 0; --i) {
			tR[i] = min(tR[i + 1], vec[i].second);
		}
		vector<ll> tL(N + 1, RL);
		for (int i = 0; i < N; ++i) {
			tL[i+1] = max(tL[i], vec[i].first);
		}

		for (int i = 0; i < N + 1; ++i) {
			ll tmp = max(0LL, R - tL[i]) + max(0LL, tR[i] - L);
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}

	return 0;
}