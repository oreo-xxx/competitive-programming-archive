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
  int N, Q; scanf("%d %d", &N, &Q);
  StarrySky<long long, long long> sk(N, (1LL<<60), 0);

  // 0 で初期化
  for (int i = 0; i < N; ++i) sk.set(i, 0);
  sk.build();

  // 各クエリ
  vector<pint> v(Q);
  for (int q = 0; q < Q; ++q) {
    int a, b; scanf("%d %d", &a, &b);
    --a;
    v[q]={a,b};
    sk.update(a, b, 1);
  }
  vector<int> ans;
  for(int i = 0; i < Q; ++i){
    int a=v[i].first;
    int b=v[i].second;
    sk.update(a,b,-1);
    if(sk.get(0,N).first > 0){ans.push_back(i+1);}
    sk.update(a,b,1);
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); ++i){
    cout << ans[i] << endl;
  }
}