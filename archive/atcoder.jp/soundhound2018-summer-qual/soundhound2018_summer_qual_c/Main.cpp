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
  ld n; ll m,d;
  cin >> n >> m >> d;
  ld tmp = n;
  if(d!=0)tmp= 2*(n-d);
  ld ans = tmp/(n*n);
  ans *= m-1;
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
