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
  int n,m,l,p,q,r;
  cin >> n >> m >> l;
  cin >> p >> q >> r;
  int ans = (n/p)*(m/q)*(l/r);
  ans = max(ans, (n/q)*(m/p)*(l/r));
  ans = max(ans, (n/p)*(m/r)*(l/q));
  ans = max(ans, (n/q)*(m/r)*(l/p));
  ans = max(ans, (n/r)*(m/p)*(l/q));
  ans = max(ans, (n/r)*(m/q)*(l/p));
  cout << ans << endl;
}
