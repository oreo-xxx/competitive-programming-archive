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

int main(){
  int n; cin >> n;
  vector<int> c(n);
  for(int i = 0; i < n; ++i)cin >> c[i];

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i==j)continue;
      if(c[i] % c[j]== 0) ++a[i];
    }
  }
  ld ans = 0;
  for(int i = 0; i < n; ++i){
    if(a[i]%2==1){
      ans += 0.5;
    }
    else{
      ld t1 = (ld)a[i]+2.0;
      ld t2 = 2.0 * (ld)a[i] + 2.0;
      ans += t1/t2;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}
