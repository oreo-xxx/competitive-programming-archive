#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    long long d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        long long p, q;
        long long d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        long long tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return make_pair(mod(r, M), M);
}


int main(){
  ll n, m;cin >> n >> m;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    b[i]= a[i]/2;
  }
  auto p = ChineseRem(b,a);
  ll ans = 0;
  if(p.first!=0 && p.first<=m){
    ans = (m-p.first)/p.second + 1;
  }
  cout << ans << endl;
}
