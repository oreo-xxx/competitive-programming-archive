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



// matrix
template<int MOD> struct Matrix {
	vector<vector<long long> > val;
	Matrix(int n, int m, long long x = 0) : val(n, vector<long long>(m, x)) {}
	void init(int n, int m, long long x = 0) { val.assign(n, vector<long long>(m, x)); }
	size_t size() const { return val.size(); }
	inline vector<long long>& operator [] (int i) { return val[i]; }
};

template<int MOD> ostream& operator << (ostream& s, Matrix<MOD> A) {
	s << endl;
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[i].size(); ++j) {
			s << A[i][j] << ", ";
		}
		s << endl;
	}
	return s;
}

template<int MOD> Matrix<MOD> operator * (Matrix<MOD> A, Matrix<MOD> B) {
	Matrix<MOD> R(A.size(), B[0].size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < B[0].size(); ++j)
			for (int k = 0; k < B.size(); ++k)
				R[i][j] = (R[i][j] ^ A[i][k] & B[k][j] );
	return R;
}

template<int MOD> Matrix<MOD> pow(Matrix<MOD> A, long long n) {
	Matrix<MOD> R(A.size(), A.size());
	for (int i = 0; i < A.size(); ++i) R[i][i] = -1;
	while (n > 0) {
		if (n & 1) R = R * A;
		A = A * A;
		n >>= 1;
	}
	return R;
}

int main() {
	int k; ll m;
	cin >> k >> m;
	Matrix<MOD> mat{ k, k };
	Matrix<MOD> vec{ k, 1 };

	for (int i = 0; i < k; ++i)	cin >> vec[k-1-i][0];

	for (int i = 0; i < k; ++i) {
		cin >> mat[0][i];
		if(i < k-1) mat[1 + i][i] = -1; // 単位元は全ビット1(=-1)
	}

	if (m - k > 0) {
		// Akのため、Cはm-k回演算する
		mat = pow(mat, m - k);
		auto ans = mat * vec;
		cout << ans[0][0] << endl;
	}
	else {
		// k >= m の場合、演算の必要なし
		cout << vec[k-m][0] << endl;
	}
	return 0;
}