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

template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

template<class T> long long inversion_number(const vector<T> &a) {
    int n = (int)a.size();
    vector<T> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    long long res = 0;
    BIT<int> bit(n);
    for (int i = 0; i < n; ++i) {
        int order = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ++order;
        res += bit.sum(1,order);
        bit.add(order, 1);
    }
    return res;
}

int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  ll lb = 0, ub= INF;
  while (ub-lb > 1){
    ll mb = (ub + lb)/2;
    vector<ll> sum(n+1);
    for(int i = 0; i < n; ++i){
      int v = -1;
      if(a[i]<=mb)v = 1;
      sum[i+ 1]= sum[i]+ v;
    }
    ll num = inversion_number(sum);
    if(num>n * (n+ 1 )/2/2)ub = mb;
    else lb = mb;
  }
  cout << ub << endl;
}
