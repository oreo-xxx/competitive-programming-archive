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

ld calc(pair<ld, ld> p){
  return sqrt(p.first*p.first + p.second*p.second);
}

int main(){
  int n; cin >> n;
  ld m = n;
  vector<pair<ld,ld>> a(n),b(n);
  ld ax=0,ay=0, bx = 0,by = 0;
  for(int i = 0; i < n; ++i){
    cin >> a[i].first >> a[i].second;
    ax+= a[i].first;
    ay+= a[i].second;
  }
  ax /= m;
  ay /= m;
  for(int i = 0; i < n; ++i){
    cin >> b[i].first >> b[i].second;
    bx+= b[i].first;
    by+= b[i].second;
  }
  bx /= m;
  by /= m;
  ld disa = 0,disb= 0;
  for(int i = 0; i < n; ++i){
    a[i].first -= ax;
    a[i].second -= ay;
    disa = max(disa, calc(a[i]));
    b[i].first -= bx;
    b[i].second -= by;
    disb = max(disb, calc(b[i]));
  }
  cout << fixed << setprecision(10);
  cout << disb/disa << endl;
}

