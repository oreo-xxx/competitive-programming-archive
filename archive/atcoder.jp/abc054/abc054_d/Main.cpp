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

ll dp[50][500][500];
int main(){
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i] >> c[i];
  }
  int M= 400;
  
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j < 500; ++j){
      for(int k = 0; k < 500; ++k){
        dp[i][j][k] = INF;
      }
    }
  }
  
  dp[0][0][0]= 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= M; ++j){
      for(int k = 0; k <= M; ++k){
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
        dp[i+1][j][k]= min(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }
  ll ans = INF;
  for(int i = 1; i <= 41; ++i){
    //cout << dp[n][ma*i][mb*i] << endl;
    ans = min(ans, dp[n][ma*i][mb*i]);
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
}
