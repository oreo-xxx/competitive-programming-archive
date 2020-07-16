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

// 二次元区間DP, メモ化, 座標圧縮

int N, W, H;
using Data = tuple<int, int, int ,int>;
vector<int> x, y;
map<Data, ll> memo{};

ll rec(int t, int b, int l, int r){
	Data key {t, b, l, r};
	if(memo.count(key)) return memo[key];
	ll ret = 0;
	for(int i = 0; i < N; ++i){
		if(l <= x[i] && x[i] < r && t <= y[i] && y[i] < b){
			ll tmp = 0;
			// 左上
			tmp += rec(t, y[i], l, x[i]);
			// 左下
			tmp += rec(y[i] + 1, b, l, x[i]);
			// 右上
			tmp += rec(t, y[i], x[i] + 1, r);
			// 右下
			tmp += rec(y[i] + 1, b, x[i] + 1, r);
			// 十字
			tmp += (b - t) + (r - l) - 1;
			ret = max(ret, tmp);
		}
	}
	memo[key] = ret;
	return ret;
}

int main(){
	cin >> W >> H >> N;
	x.resize(N);
	y.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
		--x[i]; --y[i];
	}
	ll ans = rec(0, H, 0, W);
	cout << ans << endl;
}