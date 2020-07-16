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
	ll t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

	ll suma = a1 * t1 + a2 * t2;
	ll sumb = b1 * t1 + b2 * t2;

	// 無限回会う場合を除外
	if (suma == sumb) {
		cout << "infinity" << endl;
		return 0;
	}

	// Aがどんどん離れていく状態にする
	if (suma < sumb) {
		swap(a1, b1);
		swap(a2, b2);
		swap(suma, sumb);
	}

	// t1完了時点でどこまで追い抜いているか
	ll half = t1 * (b1 - a1);

	// 追い抜いていない場合を除外
	if (half < 0) {
		cout << 0 << endl;
		return 0;
	}

	// t2完了時点でどこまで追い抜かれているか
	ll comp = suma - sumb;

	ll ans = 1 + 2 * (half / comp);
	if (half%comp == 0) --ans;
	cout << ans << endl;
	return 0;
}