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

ll GCD(ll a, ll b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
	ll g = GCD(a, b);
	return a / g * b;
}


struct fraction {
	ll num, dom;
	fraction(ll n, ll d) :num(n), dom(d) {
		ll tmp = __gcd(num, dom);
		num /= tmp;
		dom /= tmp;
	}
	fraction operator+(const fraction& a) const {
		return fraction(num*a.dom + a.num*dom, dom*a.dom);
	}
	fraction operator-(const fraction& a) const {
		return fraction(num*a.dom - a.num*dom, dom*a.dom);
	}
	fraction operator*(const fraction& a) const {
		return fraction(num*a.num, dom*a.dom);
	}
	fraction operator/(const fraction& a) {
		return fraction(num*a.dom, dom*a.num);
	}
	fraction operator*(ll k) const { return fraction(num*k, dom); }
	fraction operator/(ll k) const { return fraction(num, dom*k); }
	bool operator<(const fraction& a)const {
		return num*a.dom<a.num*dom;
	}
	bool operator>(const fraction& a)const {
		return num*a.dom>a.num*dom;
	}
	bool operator==(const fraction& a)const {
		return num*a.dom == a.num*dom;
	}
	bool operator!=(const fraction& a)const {
		return num*a.dom != a.num*dom;
	}
	bool operator<=(const fraction& a)const {
		return num*a.dom <= a.num*dom;
	}
	bool operator>=(const fraction& a)const {
		return num*a.dom >= a.num*dom;
	}
};

int main() {
	ll n; cin >> n;

	ll m = 2 * n;
	vector<vector<ld> > dp(m, vector<ld>(m));

	map<string, ll> mp;
	map<ll, string> mp2;
	int id = 0;
	for (int i = 0; i < n; ++i) {
		string s, t; ld r;
		cin >> s >> r >> t;
		if (!mp.count(s)) {
			mp[s] = id;
			mp2[id] = s;
			++id;
		}
		if (!mp.count(t)) {
			mp[t] = id;
			mp2[id] = t;
			++id;
		}
		dp[mp[s]][mp[t]] = r;
		dp[mp[t]][mp[s]] = 1.0/r;
	}
for(int _ = 0; _ < 2; ++_){
	for (int k = 0; k < m; ++k) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
                if(dp[i][j]!=0 || dp[i][k]<=0.0 || dp[k][j]<= 0.0)continue; 
				dp[i][j] = dp[i][k] * dp[k][j];
			}
		}
	}
}

	ld ans = 0;
	pint p;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ans < dp[i][j]) {
				ans = dp[i][j];
				p = { i, j };
			}
		}
	}
       ll res = ans+0.1;
	cout << 1 << mp2[p.first] << "=" << res << mp2[p.second] << endl;
}
