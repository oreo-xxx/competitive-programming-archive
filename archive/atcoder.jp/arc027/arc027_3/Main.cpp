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

int dp[610][310][611];
//見た数、買った数、消費した数

vector<int> t, h;
int main(){
  int x,y,n;cin >> x >> y >> n;
  t.resize(n);
  h.resize(n);
  for(int i = 0; i < n; ++i){
    cin >> t[i] >> h[i];
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j <= x; ++j){
      for(int k = 0; k <= x+y; ++k){
        if(k+t[i]<610){
          dp[i+1][j+1][k+t[i]]=max(dp[i+1][j+1][k+t[i]], dp[i][j][k]+h[i]);
        }
        dp[i+1][j][k]=max(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= x; ++i){
    for(int j = 0; j <= x+y; ++j){
      ans = max(ans,dp[n][i][j]);
    }
  }
  cout << ans << endl;
}
