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

int n,D,x,y;

ld calc(int u, int d, int l, int r){
  ld ans = 1.0;
  for(int i = 1; i <= n; ++i){
    ld j = i;
    ans *= j/4.0;
    if(j<=u) ans /= j;
    if(j<=d) ans /= j;
    if(j<=l) ans /= j;
    if(j<=r) ans /= j;
  }
  return ans;
}

int main(){
  ld ans = 0.0;
  cout << fixed << setprecision(10);
  cin >> n>> D>> x >> y;
  if(x%D!=0 || y%D!=0){
    cout << ans << endl;
    return 0;
  }
  int u=0,d=0,l=0,r=0;
  if(x>0)u = x/D;
  else   d = abs(x)/D;
  if(y>0)r = y/D;
  else   l = abs(y)/D;
  int rem = n-u-d-l-r;
  if(rem%2!=0){
    cout << ans << endl;
    return 0;
  }
  int m = rem/2;
  for(int i = 0; i <= m; ++i){
    int j = m-i;
    ans += calc(u+i, d+i, l+j, r+j);
  }
  cout << ans << endl;
}
