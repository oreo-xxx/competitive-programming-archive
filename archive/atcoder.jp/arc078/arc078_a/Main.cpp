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

int main() {
  int n;cin >> n;
  vector<ll> a(n), sum(n+1);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    sum[i+1]=sum[i]+a[i];
  }
  ll ans = INF;
  for(int i = 1; i < n; ++i){
    ll x = sum[i];
    ll y = sum[n]-sum[i];
    ll tmp = abs(x-y);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
