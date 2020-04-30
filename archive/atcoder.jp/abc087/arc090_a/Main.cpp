#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main() {
  ll  n;cin >>n;
  vector<vector<ll>> a(2, vector<ll>(n));
  for(int i = 0; i < 2*n; ++i){
    cin >>a[i/n][i%n];
  }
  vector<vector<ll>> sum(2,vector<ll> (n+1) );
  for(int i = 0; i < 2*n; ++i){
    sum[i/n][i%n+1]=sum[i/n][i%n]+a[i/n][i%n];
  }
  ll ans =0;
  for(int i = 0; i < n; ++i){
    ll tmp=sum[0][i+1]+sum[1][n]-sum[1][i];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}