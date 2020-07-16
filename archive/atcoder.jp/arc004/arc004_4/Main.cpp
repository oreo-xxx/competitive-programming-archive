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

using mint = Fp<MOD>;

vector<pll> prime_factorize(ll n) {
    vector<pll> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}


const int MAX = 200100;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    COMinit();
    int N, M; cin >> N >> M;
	bool f = false;
	if (N < 0) {
		f = true;
		N = abs(N);
	}
    vector<pll> vec = prime_factorize(N);
    mint ans = 1;
    for (auto itr : vec) {
        ll tmp = COM(itr.second + M - 1, M - 1);
        ans = ans * tmp;
    }
	mint two = 2;
	ans *= modpow(two, M-1);
    cout << ans << endl;
    return 0;
}

