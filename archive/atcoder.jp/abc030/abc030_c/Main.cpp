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
  ll n,m, x, y; cin >> n >> m>> x >> y;
  vector<ll> a(n), b(m);
  for(int i = 0; i < n; ++i)cin >> a[i];
  for(int i = 0; i < m; ++i)cin >> b[i];
  ll now = 0;
  int ans = 0;
  while(true){
    int i = lower_bound(a.begin(), a.end(), now)-a.begin();
    if(i==n) break;
    now = a[i] + x;
    int j = lower_bound(b.begin(), b.end(), now)-b.begin();
    if(j==m) break;
    now = b[j] + y;
    ++ans;
  }
  cout << ans << endl;
}
