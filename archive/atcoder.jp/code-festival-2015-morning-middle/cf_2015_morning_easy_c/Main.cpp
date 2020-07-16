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

int main() {
	ll n, k, m, r; cin >> n >> k >> m >> r;
	vector<ll> a(n);
	for(int i = 0; i < n-1; ++i)cin >> a[i];
	sort(a.begin(), a.end(), greater<ll>());
 
 	ll border = r * k;
	ll sum = 0;
	for(int i = 0; i < k-1; ++i) sum += a[i];
	ll ans = border - sum;
	if(a[k - 1] >= ans) ans = 0;
	if(ans > m) ans = -1;
	cout << ans << endl;
}