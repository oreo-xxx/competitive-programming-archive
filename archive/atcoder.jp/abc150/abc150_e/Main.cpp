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

template<class T> struct BiCoef {
	vector<T> fact_, inv_, finv_;
	BiCoef() {}
	BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
		init(n);
	}
	void init(int n) noexcept {
		fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
		int MOD = fact_[0].getmod();
		for (int i = 2; i < n; i++) {
			fact_[i] = fact_[i - 1] * i;
			inv_[i] = -inv_[MOD%i] * (MOD / i);
			finv_[i] = finv_[i - 1] * inv_[i];
		}
	}
	T com(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return fact_[n] * finv_[k] * finv_[n - k];
	}
	T fact(int n) const noexcept {
		if (n < 0) return 0;
		return fact_[n];
	}
	T inv(int n) const noexcept {
		if (n < 0) return 0;
		return inv_[n];
	}
	T finv(int n) const noexcept {
		if (n < 0) return 0;
		return finv_[n];
	}
};

using mint = Fp<MOD>;

int main() {
	ll n; cin >> n;
	vector<ll> c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];
	sort(c.begin(), c.end());

	mint ans = 0, f = 4;
	for (int i = 0; i < n; ++i) {
		ans += c[i] * (n+1-i);
	}

	ans *= modpow(f, n - 1);
	cout << ans << endl;

	/* 遅い回答。これの高速化が上記。数学力、あるいは
	サンプルで各要素が何回足されたか数えれば上記を導ける。
	BiCoef<mint> bc;
	bc.init(210000);
	for (int num = 1; num <= n; ++num) {
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= num; ++j) {
				mint tmp = j * c[i];
				ans += tmp * bc.com(n - 1 - i, j - 1) * bc.com(i, num - j);
			}
		}
	}
	mint two = 2;
	ans *= modpow(two, n);
	*/
}