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

template<int MOD> struct Fp {
	long long val;
	Fp(long long v = 0) noexcept : val(v % MOD) {
		if (val < 0) v += MOD;
	}
	int getmod() { return MOD; }
	Fp operator - () const noexcept {
		return val ? MOD - val : 0;
	}
	Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
	Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
	Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
	Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
	Fp& operator += (const Fp& r) noexcept {
		val += r.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	Fp& operator -= (const Fp& r) noexcept {
		val -= r.val;
		if (val < 0) val += MOD;
		return *this;
	}
	Fp& operator *= (const Fp& r) noexcept {
		val = val * r.val % MOD;
		return *this;
	}
	Fp& operator /= (const Fp& r) noexcept {
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
	bool operator == (const Fp& r) const noexcept {
		return this->val == r.val;
	}
	bool operator != (const Fp& r) const noexcept {
		return this->val != r.val;
	}
	friend ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
		return os << x.val;
	}
	friend istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
		return is >> x.val;
	}
	friend Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
		if (n == 0) return 1;
		auto t = modpow(a, n / 2);
		t = t * t;
		if (n & 1) t = t * a;
		return t;
	}
};

using mint = Fp<MOD>;

int main() {
	int m; cin >> m;

	ll sum = 0, keta = 0;
	for (int i = 0; i < m; ++i) {
		ll c, d; cin >> c >> d;
		sum += c * d;
		keta += d;
	}
	ll ans = keta - 1 + (sum-1) / 9L;
	cout << ans << endl;

	return 0;
}