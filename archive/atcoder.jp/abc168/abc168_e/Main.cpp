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

template<int MOD> struct Fp {
	long long val;
	Fp(long long v = 0) : val(v % MOD) {
		if (val < 0) v += MOD;
	}
	int getmod() { return MOD; }
	Fp operator - () const {
		return val ? MOD - val : 0;
	}
	Fp operator + (const Fp& r) const { return Fp(*this) += r; }
	Fp operator - (const Fp& r) const { return Fp(*this) -= r; }
	Fp operator * (const Fp& r) const { return Fp(*this) *= r; }
	Fp operator / (const Fp& r) const { return Fp(*this) /= r; }
	Fp& operator += (const Fp& r) {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	Fp& operator -= (const Fp& r) {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	Fp& operator *= (const Fp& r) {
		val = val * r.val % MOD;
		return *this;
	}
	Fp& operator /= (const Fp& r) {
		long long a = r.val, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	bool operator == (const Fp& r) const {
		return this->val == r.val;
	}
	bool operator != (const Fp& r) const {
		return this->val != r.val;
	}
	friend ostream& operator << (ostream &os, const Fp<MOD>& x) {
		return os << x.val;
	}
	friend istream& operator >> (istream &is, Fp<MOD>& x) {
		return is >> x.val;
	}
	friend Fp<MOD> modpow(const Fp<MOD> &a, long long n) {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};

using mint = Fp<MOD>;

ll GCD(ll a, ll b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

using Data = tuple<int, ll, ll>;

int main(){
	ll n; cin >> n;
	map<Data, ll> mp;
	for(int i = 0; i < n; ++i){
		ll a, b; cin >> a >> b;
		if(a == 0 && b == 0) ++mp[{0,0,0}];
		else if (a == 0 && b != 0) ++mp[{0, 0, 1}];
		else if(a != 0 && b == 0) ++mp[{0,1,0}];
		else{
			int sign = 1;
			if (a < 0 && b > 0) sign = -1;
                        if (a > 0 && b < 0) sign = -1;
			a = abs(a); 
			b = abs(b);
			ll tmp = GCD(a, b);
			++mp[{sign, a/tmp, b/tmp}];
		}
	}

    mint ans = 1, sub = 0, two = 2;
	set<Data> se;
	for(auto it : mp){
		if (se.count(it.first)) continue;

		int sign = get<0>(it.first);
		ll a     = get<1>(it.first);
		ll b     = get<2>(it.first);
		ll p = it.second;

		if(a == 0 && b == 0) sub = p;
		else{
			ll q = 0;
			if(mp.count({-sign, b, a}) != 0){
				q += mp[{-sign, b, a}];
				se.insert({-sign, b, a});
			}
			mint tmp = modpow(two, p) + modpow(two, q) - 1;
			ans *= tmp;
		}
	}
	ans += sub - 1;
	cout << ans << endl;
	return 0;
}
