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

vector<string> s;
vector<char> ans;
int a[3];
char cs[3] = { 'A','B','C' };
bool f = false;
int n;
bool func(int i, int x, int y) {
	if (a[x] == 0 && a[y] == 0) {
		f = true;
		return true;
	}
	if (a[x] > a[y]) {
		ans[i] = cs[y];
		--a[x]; ++a[y];
	}
	else if (a[y] > a[x]) {
		ans[i] = cs[x];
		--a[y]; ++a[x];
	}
	else {
		if (i == n - 1) {
			ans[i] = cs[y];
			--a[x]; ++a[y];
			return true;
		}
		return false;
	}
	return true;
}

int main(){
	cin >> n >> a[0] >> a[1] >> a[2];

	ans.resize(n);
	s.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++)
	{
		if (s[i] == "AB") {
			bool tmp = func(i, 0, 1);
			if (tmp) continue;
			if (s[i + 1] == "AB") {
				ans[i] = cs[1];
				--a[0]; ++a[1];
			}
			if (s[i + 1] == "BC") {
				ans[i] = cs[1];
				--a[0]; ++a[1];
			}
			if (s[i + 1] == "AC") {
				ans[i] = cs[0];
				--a[1]; ++a[0];
			}
		}
		if (s[i] == "AC") {
			bool tmp = func(i, 0, 2);
			if (tmp) continue;
			if (s[i + 1] == "AB") {
				ans[i] = cs[0];
				--a[2]; ++a[0];
			}
			if (s[i + 1] == "BC") {
				ans[i] = cs[2];
				--a[0]; ++a[2];
			}
			if (s[i + 1] == "AC") {
				ans[i] = cs[0];
				--a[2]; ++a[0];
			}
		}
		if (s[i] == "BC") {
			bool tmp = func(i, 1, 2);
			if (tmp) continue;
			if (s[i + 1] == "AB") {
				ans[i] = cs[1];
				--a[2]; ++a[1];
			}
			if (s[i + 1] == "BC") {
				ans[i] = cs[2];
				--a[1]; ++a[2];
			}
			if (s[i + 1] == "AC") {
				ans[i] = cs[2];
				--a[1]; ++a[2];
			}
		}
		if (f) break;
	}
	if (f) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}