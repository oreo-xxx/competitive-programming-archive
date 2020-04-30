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

int n;
vector<ld> x,y,c;
bool check(ld r){
  for(int i = 0; i < n; ++i){
    for(int j = i+ 1; j < n; ++j){
      ld xd = abs(x[i]-x[j]);
      ld yd = abs(y[i]-y[j]);
      ld M = r / c[i] + r/c[j];
      if(xd>M || yd >M){
        return false; 
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  x.resize(n);
  y.resize(n);
  c.resize(n);
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> y[i] >> c[i];
  }
  ld lb = 0.0, ub = (ld)INF32;
  for(int i = 0; i < 50; ++i){
    ld mb = (lb+ub)/2.0;
    //cout << mb << endl;
    if(check(mb)){
      ub = mb;
    }
    else{
      lb = mb;
    }
  }
  cout << fixed << setprecision(10)<< ub << endl;
}
