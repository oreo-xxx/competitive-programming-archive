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

ld calc(ld r, ld h){
  return r * r* h * M_PI / 3.0;
}

int main() {
  int n,q;cin >> n >> q;
  vector<ld> x(n),r(n),h(n);
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> r[i] >> h[i];
  }
  
  for(int _ = 0; _ < q; ++_){
    ld a,b;cin >> a >> b;
    ld v = 0;
    for(int i = 0; i < n; ++i){
      ld vall = calc(r[i], h[i]);
      ld ra = r[i] * (x[i]+h[i]-a) / h[i];
      ld va = calc(ra, x[i]+h[i]-a);
      ld rb = r[i] * (x[i]+h[i]-b) / h[i];
      ld vb = calc(rb, x[i]+h[i]-b);
      if(a<= x[i] && x[i]+h[i]<= b){
        v += vall;
      }
      else if(a<= x[i] && b>x[i] && x[i]+h[i] > b){
        v += vall -vb;
        
      }
      else if(a> x[i] && a <= x[i]+h[i] && x[i]+h[i]<= b){
        v += va;
      }
      else if(a> x[i] && x[i]+h[i]> b){
        v += va-vb;
      }
    }
    cout << fixed << setprecision(10)<< v << endl;
  }
}
