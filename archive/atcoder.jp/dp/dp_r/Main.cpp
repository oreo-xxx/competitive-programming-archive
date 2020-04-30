#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

// matrix
template<int MOD> struct Matrix {
    vector<vector<long long> > val;
    Matrix(int n, int m, long long x = 0) : val(n, vector<long long>(m, x)) {}
    void init(int n, int m, long long x = 0) {val.assign(n, vector<long long>(m, x));}
    size_t size() const {return val.size();}
    inline vector<long long>& operator [] (int i) {return val[i];}
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
                R[i][j] = (R[i][j] + A[i][k] * B[k][j] % MOD) % MOD; 
    return R;
}

template<int MOD> Matrix<MOD> pow(Matrix<MOD> A, long long n) {
    Matrix<MOD> R(A.size(), A.size());
    for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
     int n; ll k;    cin >>n >> k;
     Matrix<MOD> mat{n, n};
     
     for(int i = 0; i < n; ++i){
         for(int j = 0; j < n; ++j){
              cin >> mat[i][j];
         }
     }
    
    mat = pow(mat, k);
    
    ll ans = 0;
    for(int i = 0; i < n; ++i){
         for(int j = 0; j < n; ++j){
              ans += mat[i][j];
              ans %= MOD;
         }
     }
     cout << ans << endl;
}