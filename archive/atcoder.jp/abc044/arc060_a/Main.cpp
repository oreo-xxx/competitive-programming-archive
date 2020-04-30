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
 
ll dp[51][51][2510] {};

int main(){
  int n,t;cin >> n >> t;
  vector<int> a(n);
  int A = 0;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    A=max(A,a[i]);
  }
  int M = n * A;
  
  dp[0][0][0]= 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= i; ++j){
      for(int k = 0; k <= M; ++k){
        dp[i+1][j+1][k+a[i]] += dp[i][j][k];
        dp[i+1][j][k] += dp[i][j][k];
      }
    }
  }
  ll ans = 0;
  for(int i = 1; i <=  n; ++i){
    ans += dp[n][i][i*t];
  }
  cout << ans << endl;
}
