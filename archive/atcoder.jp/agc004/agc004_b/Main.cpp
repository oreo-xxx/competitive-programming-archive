#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

template<class Monoid, class Action> struct StarrySky {
    const Monoid INF;
    const Action ZERO;
    int SIZE;
    vector<pair<Monoid, int> > dat;
    vector<Action> lazy;
    
    StarrySky(int n, const Monoid &inf, const Action &zero) : INF(inf), ZERO(zero) {
        init(n);
    }
    void init(int n) {
        SIZE = 1;
        while (SIZE < n) SIZE <<= 1;
        dat.assign(SIZE * 2, {INF, -1});
        lazy.assign(SIZE * 2, ZERO);
    }
    
    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = {v, a}; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = min(dat[k*2], dat[k*2+1]);
    }
    
    /* update [a, b) */
    inline void evaluate(int k) {
        if (lazy[k] == ZERO) return;
        if (k < SIZE) lazy[k*2] += lazy[k], lazy[k*2+1] += lazy[k];
        dat[k].first += lazy[k];
        lazy[k] = ZERO;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b) lazy[k] += v, evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k*2, l, (l+r)>>1), update(a, b, v, k*2+1, (l+r)>>1, r);
            dat[k] = min(dat[k*2], dat[k*2+1]);
        }
    }
    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }
    
    /* get [a, b) */
    inline pair<Monoid,int> get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return min(get(a, b, k*2, l, (l+r)>>1), get(a, b, k*2+1, (l+r)>>1, r));
        else
            return {INF, -1};
    }
    inline pair<Monoid,int> get(int a, int b) { return get(a, b, 1, 0, SIZE); }
    inline Monoid operator [] (int a) { return get(a, a+1).first; }
    
    /* debug */
    void print() {
        for (int i = 0; i < SIZE; ++i) { cout << (*this)[i]; if (i != SIZE) cout << ","; }
        cout << endl;
    }
};

int main() {
  ll n,x;cin >>n>> x;
  vector<ll> a(n);
  StarrySky<long long, long long> sk(2*n, (1LL<<60), 0);

  for(int i = 0; i < n; ++i){
    cin >>a[i];
    sk.set(i, a[i]);
    sk.set(i+n,a[i]);
  }
  sk.build();

  ll ans = INF;
  for(int i = 0; i < n; ++i){
    ll tmp = i* x;
    for(int j = 0; j < n; ++j){
         ll b = sk.get(j+n-i, j+n+1).first ;
         tmp+=b;
    }
    ans  = min(ans, tmp);
  }
  cout << ans << endl;
}
